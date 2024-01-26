# [연속 도색 시스템](https://www.notion.so/f5c4cea4ff7e47759dcb0cc4d525c49b?pvs=4)

---

# **👆🏻프로젝트 개요**

- **개발 환경**
    - Windows
    - HMI
        - InTouch
    - PLC
        - InTouch 내부 Script로 대체

- **개발 기간**
    - 2023/11/05 ~ 2023/11/06

- **회고**
    - 경험
        - XP - Builder 보다 다양한 종류의 UI 및 기능 활용
        - 하나의 태그로 전체적인 흐름을 스크립트로 작성 - C언어
    - 보완 사항
        - PLC 연동
        - 메모리 할당

---

# 💡 **프로젝트 설명**

**✅ 일시 정지 및 속도 조절이 가능한 도색 시스템을 InTouch를 활용하여 만들었습니다.**

- 시스템 **매커니즘**
    - speed 슬라이더로 컨베이어 벨트 속도 및 일시 정지
    - position 0 ~ 50 : 도색 전 드럼통 이동
    - position 51 ~ 100 : 도색 후 드럼통 이동

- Script **설계**
    1. position : 0 ~ 100 반복
    2. speed : 
        1. 0 : position이 제 자리 유지
        2. 1 ~ 5 : 1ms 당 position의 속도 지정
    3. box :
        1. position이 0 ~ 10일 때 열림
        2. position이 11 ~ 100일 때 닫힘
    4. box2 : 
        1. position이 0 ~ 89일 때 닫힘
        2. position이 90 ~ 100일 때 열림
            
            ![KakaoTalk_Photo_2023-11-14-14-07-06_003png](https://github.com/jongsoo0603/codingOn/assets/98942866/d234ede4-2d28-4e3e-9ae2-6fcb80ea38fa)
            
    

---

# 📺 시연 영상

[![Video Label](http://img.youtube.com/vi/ZgCF1pv5VKo/0.jpg)](https://youtu.be/ZgCF1pv5VKo?si=KOPWaT-G5evV-ihk)

---