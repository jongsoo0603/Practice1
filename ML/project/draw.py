import cv2  # OpenCV 라이브러리, 이미지 및 비디오 처리에 사용됩니다.
import dlib  # Dlib 라이브러리, 얼굴 검출과 랜드마크 예측에 사용됩니다.
import numpy as np  # NumPy 라이브러리, 수치 계산에 사용됩니다.
from imutils import face_utils  # face_utils 모듈, 얼굴 관련 유틸리티 함수들이 포함되어 있습니다.
from keras.models import load_model  # Keras 라이브러리, 딥러닝 모델을 로드하기 위해 사용됩니다.
from PIL import ImageFont, ImageDraw, Image  # Pillow 라이브러리, 이미지를 다루는데 사용됩니다.
import time  # 시간 관련 기능을 사용하기 위해 사용됩니다.
import os  # 운영체제와 상호 작용하기 위해 사용됩니다.
import pygame  # Pygame 라이브러리, 음악 및 사운드 재생에 사용됩니다.
# DisplayHand 모듈, 손에 대한 디스플레이 기능이 정의되어 있습니다.


# 사용할 클래스가 담긴 파일 분리
from utils_display import DisplayHand
from utils_mediapipe import MediaPipeHand  # MediaPipeHand 모듈, 손을 인식하는 데 사용됩니다.
# GestureRecognition 모듈, 제스처 인식에 사용됩니다.
from utils_joint_angle import GestureRecognition


# 경로 출력 관련 함수 파일 분리
from tMap import printMap


# ---------- 전역 변수, 상수 선언 ----------#
IMG_SIZE = (34, 26)  # 눈 사진 사이즈 설정
LIP_SIZE = (10, 10)  # 입 사진 사이즈 설정

# 나눔폰트 로드
font_path = 'media/NanumGothic.ttf'
font_size = 60
font = ImageFont.truetype(font_path, font_size)


# ---------- 얼굴 인식 관련 변수 선언 ----------#

# 학습시킨 눈과, 입 모델 호출
try:
    model = load_model('models/eyeModel.h5')
    lipModel = load_model('models/lipModel.h5')
except Exception as e:
    print(f"모델 로딩 중 에러 발생: {str(e)}")
    exit(1)

# 입, 눈, 얼굴 인식 횟수 및 시간 초기화
lipCount = 0
lip_close_time = 0
lipOpen = False
lip_open_time = time.time()
eyes_open_time = time.time()
last_face_time = time.time()

# 얼굴 감지기 및 랜드마크 예측기 초기화
detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor(
    'models/shape_predictor_68_face_landmarks.dat')


# ---------- 손 인식 관련 변수 선언 ----------#

# mediapipe hand 클래스 로드
pipe = MediaPipeHand(static_image_mode=False, max_num_hands=4)

# 디스플레이 클래스 로드
disp = DisplayHand(max_num_hands=1)

# 제스처 인식 클래스 로드
gest = GestureRecognition("eval")

# 'home' 제스처가 인식된 시간을 저장하는 변수
home_start_time = None


def speak(img, text):  # 경고음, TTS, 텍스트 출력 함수
    # 한글 출력
    pil_img = Image.fromarray(img)
    draw = ImageDraw.Draw(pil_img)

    # 텍스트 크기와 색상 설정
    text_width, text_height = draw.textsize(text, font)
    text_position = ((img.shape[1] - text_width) // 2, 50)
    text_color = (0, 0, 255)  # 빨간색

    # 배경을 검은색으로 설정
    bg_position = (text_position[0] - 10, text_position[1] - 10)
    bg_size = (text_width + 20, text_height + 20)
    draw.rectangle([bg_position, (bg_position[0] + bg_size[0],
                   bg_position[1] + bg_size[1])], fill=(0, 0, 0))

    # 텍스트 삽입
    draw.text(text_position, text, font=font, fill=text_color)
    img = np.array(pil_img)

    # 경고음 출력
    pygame.mixer.init()
    pygame.mixer.music.load("media/warning.mp3")
    pygame.mixer.music.play()
    os.system(f'say "{text}"')  # TTS

    return draw, img


def crop_area(img, points, size):  # 눈과 입의 범위를 자르는 함수

    x1, y1 = np.amin(points, axis=0)
    x2, y2 = np.amax(points, axis=0)
    cx, cy = (x1 + x2) / 2, (y1 + y2) / 2

    w = (x2 - x1) * 1.2
    h = w * size[1] / size[0]

    margin_x, margin_y = w / 2, h / 2

    min_x, min_y = int(cx - margin_x), int(cy - margin_y)
    max_x, max_y = int(cx + margin_x), int(cy + margin_y)

    rect = np.rint([min_x, min_y, max_x, max_y]).astype(int)

    cropped_img = img[rect[1]:rect[3], rect[0]:rect[2]]

    return cropped_img, rect


def midpoint(rect):  # 눈, 입의 중심 좌표 계산 함수
    midpoint_x = (rect[0] + rect[2]) // 2
    midpoint_y = rect[1]
    return midpoint_x, midpoint_y


def eyeFunc(img, leftPre, rightPre, lipPre):  # 눈 기능 함수
    # 얼굴 인식 관련 변수 함수 내에 전역변수 설정
    global eyes_open_time, lip_close_time, lip_open_time, lipOpen, lipCount
    draw = None  # 초기화

    if leftPre > 0.9 and rightPre > 0.9:
        eyes_open_time = time.time()
    else:
        if time.time() - eyes_open_time > 1:  # 눈을 작게 뜨면
            draw, img = speak(img, "눈을 뜨세요")

    if lipPre < 0.9:
        lip_close_time = time.time()
        lipOpen = False
    else:
        if (time.time() - lip_close_time > 1) and (not lipOpen):
            lipCount += 1
            lipOpen = True
            if time.time() - lip_open_time > 10:
                lip_open_time = time.time()
            else:
                if lipCount >= 2:
                    draw, img = speak(img, "두 번째 하품")  # 10초 내에 하품을 두 번 한다면
                    lipCount = 0
                lip_open_time = time.time()
    return draw, img


def handFunc(gray, img):  # 손 기능 함수
    # 얼굴과 손 인식 관련 변수 함수 내에 전역변수 설정
    global pipe, disp, gest, home_start_time

    requireTime = ""  # 소요시간 초기화

    # 피드포워드를 통해 키포인트 추출
    param = pipe.forward(gray)

    if param[0]['class'] is not None:
        param[0]['gesture'] = gest.eval(param[0]['angle'])
        if param[0]['gesture'] == 'home':
            if home_start_time is None:
                home_start_time = time.time()
            else:
                elapsed_time = time.time() - home_start_time
                if elapsed_time > 3:
                    printMap()  # 지도 출력, TTS
                    home_start_time = None
        else:
            home_start_time = None

    # 손의 키포인트를 2D로 img에 그려 넣기
    disp.draw2d(img, param)

    return img


def drawImage(img):  # 메인 함수

    # 얼굴 인식 관련 변수 함수 내에 전역변수 설정
    global last_face_time

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # 얼굴 감지
    faces = detector(gray)

    # 얼굴이 감지된 경우
    if len(faces) > 0:
        last_face_time = time.time()
        face = faces[0]
        shapes = predictor(gray, face)
        shapes = face_utils.shape_to_np(shapes)

        # 각 부위에 대한 정보를 담은 딕셔너리
        # 'left_eye', 'right_eye', 'lip' 각 부위에 대해 점의 범위, 이미지 크기, 사용할 모델 정보를 가지고 있습니다.
        parts = {
            'left_eye': {'points': shapes[36:42], 'size': IMG_SIZE, 'model': model},
            'right_eye': {'points': shapes[42:48], 'size': IMG_SIZE, 'model': model},
            'lip': {'points': shapes[48:60], 'size': LIP_SIZE, 'model': lipModel},
        }

        # 예측값을 저장할 딕셔너리
        predictions = {}

        # 각 부위에 대해 동일한 작업을 수행
        for part, data in parts.items():
            # crop_area 함수를 사용하여 이미지의 특정 부분(눈 혹은 입)을 잘라내고, 잘라낸 부분의 사각형 좌표를 가져옵니다.
            img_part, rect = crop_area(
                gray, points=data['points'], size=data['size'])

            # 잘라낸 이미지를 설정된 크기로 변환합니다.
            img_part = cv2.resize(img_part, dsize=data['size'])

            # 오른쪽 눈의 경우, 이미지를 좌우 반전시킵니다. 이는 눈동자의 위치를 맞추기 위한 조치입니다.
            if part == 'right_eye':
                img_part = cv2.flip(img_part, flipCode=1)

            # 잘라낸 이미지를 모델에 입력할 수 있는 형태로 변환하고, 정규화를 수행합니다.
            input_part = img_part.copy().reshape(
                (1, data['size'][1], data['size'][0], 1)).astype(np.float32) / 255.

            # 해당 부위에 대한 모델을 사용하여 예측을 수행합니다.
            pred = data['model'].predict(input_part)

            # 예측값을 딕셔너리에 저장합니다. 이 예측값은 이후에 다른 작업에 활용될 수 있습니다.
            predictions[part] = pred

            # 예측값을 문자열 형태로 변환합니다. 이 문자열은 이미지에 출력됩니다.
            str_pred = '%.1f' % pred

            # 원본 이미지에 잘라낸 부위를 표시하는 사각형을 그립니다.
            cv2.rectangle(img, pt1=tuple(rect[0:2]), pt2=tuple(
                rect[2:4]), color=(255, 255, 255), thickness=2)

            # 사각형의 중심 좌표를 계산합니다.
            midpoint_part = midpoint(rect)

            # 계산한 중심 좌표에 예측값을 텍스트로 출력합니다.
            cv2.putText(img, str_pred, midpoint_part,
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

        # 눈과 입의 예측치를 인자를 넣으면 경고음, TTS, 텍스트를 출력하는 함수
        draw, img = eyeFunc(
            img, predictions['left_eye'], predictions['right_eye'], predictions['lip'])

    # 얼굴이 감지되지 않은 경우
    else:
        if time.time() - last_face_time > 1:
            draw, img = speak(img, "앞을 보세요")  # 얼굴 인식이 안된다면

    # 손가락 관절을 인식하고 특정 제스쳐 인식하면 집까지의 경로 출력
    img = handFunc(gray, img)

    return img
