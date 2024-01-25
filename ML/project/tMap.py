import requests
import folium
import json
from selenium import webdriver
from datetime import datetime, timedelta
import time
import os


# IP 주소로 위도, 경도를 반환하는 함수
def get_coordinates():
    key = 'c887f69dd63ddb1cd9d4f53408974e46'
    send_url = 'http://api.ipstack.com/check?access_key=' + key

    r = requests.get(send_url)
    j = json.loads(r.text)

    lat = j['latitude']
    lon = j['longitude']
    return str(lat) + ", " + str(lon)


# Tmap 경로 정보를 반환하는 함수
def get_route_info(start, end):
    APP_KEY = "HpVe5crDV38GvHu7tUyMA5CSmhca5PQk3vRWkFH0"

    headers = {
        "appKey": APP_KEY
    }

    url = f"https://api2.sktelecom.com/tmap/routes?version=1&format=json&startX={start.split(',')[1]}&startY={start.split(',')[0]}&endX={end.split(',')[1]}&endY={end.split(',')[0]}"

    response = requests.get(url, headers=headers)

    if response.status_code == 200:
        return response.json()["features"]
    else:
        print("Tmap api 에러:", response.status_code)
        return None


# 메인 함수 - 지도 출력
def printMap():

    # 현재 위치 위경도 API
    start = get_coordinates()
    # start = "37.54760, 126.9457"  # 코딩온 위경도
    end = "37.49445623129658, 126.87651528717959"  # 집의 위경도 설정

    # 경로 정보를 얻는다
    routes_info = get_route_info(start, end)
    if routes_info is None:
        return

    # 경로 정보에서 좌표를 추출한다
    path_coordinates = [[coord[1], coord[0]] for feature in routes_info if feature["geometry"]
                        ["type"] == "LineString" for coord in feature["geometry"]["coordinates"]]

    # 이동 시간을 계산한다
    total_time = sum([feature["properties"]["totalTime"]
                     for feature in routes_info if "totalTime" in feature["properties"]])
    future_time = datetime.now() + timedelta(seconds=total_time)

    # 도착 시간을 계산한다
    arrivalTime = f"예상 도착 시간: {future_time.hour}시 {future_time.minute}분"

    # 이동 시간을 시, 분, 초로 나누어 저장
    if total_time > 60:
        min = total_time // 60
        sec = total_time % 60
        if min > 60:
            hour = min // 60
            min = min % 60
            requireTime = str(hour) + "시간 " + str(min) + "분 " + str(sec) + "초"
        else:
            requireTime = str(min) + "분 " + str(sec) + "초"
    else:
        requireTime = str(total_time) + "초"
    requireTime = f"예상 이동 시간: {requireTime}"

    # 이동 거리를 계산한다
    total_distance_km = sum([feature["properties"]["totalDistance"]
                            for feature in routes_info if "totalDistance" in feature["properties"]]) / 1000

    # zoom level을 결정한다
    if 0 <= total_distance_km <= 15:
        zoom_level = 13
    elif 15.1 <= total_distance_km <= 30:
        zoom_level = 12
    elif 30.1 <= total_distance_km <= 110:
        zoom_level = 11
    elif 110.1 <= total_distance_km <= 230:
        zoom_level = 10
    elif 230.1 <= total_distance_km <= 400:
        zoom_level = 9
    else:
        zoom_level = 8

    # 지도의 중심 좌표를 계산한다
    midpoint_lat = (float(start.split(',')[0]) + float(end.split(',')[0])) / 2
    midpoint_lon = (float(start.split(',')[1]) + float(end.split(',')[1])) / 2

    # 지도를 생성한다
    map = folium.Map(
        location=[midpoint_lat, midpoint_lon], zoom_start=zoom_level)

    # 지도에 마커를 추가한다
    start_marker = folium.Marker(location=path_coordinates[0], popup=folium.Popup(
        '<strong>현재위치</strong><br>'+requireTime, max_width=300, show=True), icon=folium.Icon(color='blue', icon="fa-solid fa-car", prefix='fa-solid'))
    end_marker = folium.Marker(location=path_coordinates[-1], popup=folium.Popup(
        '<strong>집</strong><br>'+arrivalTime, max_width=300, show=True), icon=folium.Icon(color='red', icon="fa-solid fa-house", prefix='fa-solid'))

    start_marker.add_to(map)
    end_marker.add_to(map)

    # 지도에 선을 그린다
    folium.PolyLine(path_coordinates, color="black",
                    weight=8, opacity=1).add_to(map)

    map.save(
        '/Users/shinjongsoo/Desktop/codingOn/google-mediapipe/code/media/map.html')

    os.system(f'say "집 까지의 {requireTime}"')  # TTS

    # 웹 드라이버를 생성하고 HTML 파일을 연다
    driver = webdriver.Safari()
    driver.set_window_size(1920, 1080)
    file_path = 'file://' + \
        os.path.realpath(
            '/Users/shinjongsoo/Desktop/codingOn/google-mediapipe/code/media/map.html')
    driver.get(file_path)

    # 10초 동안 대기한 후 웹 드라이버를 종료한다
    time.sleep(10)
    driver.close()
