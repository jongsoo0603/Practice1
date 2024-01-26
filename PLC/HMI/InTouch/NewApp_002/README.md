# [차량 기준 신호등](https://www.notion.so/b3db164b90284db696b659e0fabe2de4?pvs=4)

---

# **👆🏻프로젝트 개요**

- **개발 환경**
    - Windows
    - HMI
        - InTouch
    - PLC
        - InTouch 내부 Script로 대체

- **개발 기간**
    - 2023/11/07 ~ 2023/11/08

- **회고**
    - 경험
        - XP - Builder 보다 다양한 종류의 UI 및 기능 활용
        - 하나의 태그로 전체적인 흐름을 스크립트로 작성 - C언어
    - 보완 사항
        - PLC 연동
        - 메모리 할당

---

# 💡 **프로젝트 설명**

**✅ 차량 입장**에서의 1차선 신호등을 HMI로 구현했습니다.

- **신호 매커니즘**
    
     - <span style="color:green">녹색</span> 신호
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;항상 :
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1ms 마다 10 씩 이동
    
    - <span style="color:orange">황색</span> 신호
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;정지선 이전 :
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;정지선까지 1ms 마다 10 씩 이동 후 정지선 앞에서 정지
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;딜레마 존 내부 :
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;딜레마 존 탈출까지 1ms 마다 30 씩 이동
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;딜레마 존 탈출 후 :
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1ms 마다 10 씩 이동
    
    - <span style="color:red">적색</span> 신호
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;정지선 이전 :
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;정지선까지 1ms 마다 10 씩 이동 후 정지선 앞에서 정지
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;정지선 이후 :
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1ms 마다 10 씩 이동
    

<details>
<summary>Script 설계</summary>
<div markdown="1">

- 6초 이전 : 1ms 마다 + 1, 6초 이후 : 0으로 초기화
    - 차량 양 쪽 끝에 닿으면 원래 자리로 초기화
    
        ![1](https://github.com/jongsoo0603/codingOn/assets/98942866/6420184c-2f70-4c93-851e-33de9a15d196)
    
- 녹색 신호 시점
    
    ![2](https://github.com/jongsoo0603/codingOn/assets/98942866/c53c8fa6-f494-4a4f-aea1-ff9cc6037311)
    
- 황색 신호 시점
    
    ![3](https://github.com/jongsoo0603/codingOn/assets/98942866/a375290c-bf73-46eb-9c6a-3954a0ebdebf)
    
- 적색 신호 시점
    
    ![4](https://github.com/jongsoo0603/codingOn/assets/98942866/a1a7c1e1-45ed-4996-8c36-d36cfa94fdc4)

</div>
</details>

---

# 📺 시연 영상

0 ~ 2 초 : 녹색 신호, 2 ~ 4 초 : 황색 신호, 4 ~ 6 초 : 적색 신호
[![Video Label](http://img.youtube.com/vi/70mZePW2xls/0.jpg)](https://youtu.be/70mZePW2xls?si=rlK0qZX9jbhCrTQL)

---