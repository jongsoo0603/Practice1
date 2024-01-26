# [사거리 신호등](https://www.notion.so/87f7542cd5124fd3af4e9f1404746500?pvs=4)

---

# 👆🏻프로젝트 개요

- 개발 환경
    - Windows
    - PLC
        - XG-5000
    - HMI
        - XP-Builder

- 개발 기간
    - 2023/11/02 ~ 2023/11/04

- 회고
    - 경험
        - PLC ↔ HMI 연동
        - PLC 활용 및 설계의 이해
        - HMI로 UI  활용
        - 100% PLC로 구현 ⭕
            - HMI 스크립트 활용 ❌
    - 보완 사항
        - 효율적인 PLC 설계
        - 불필요한 PLC 정리

---

# 💡 프로젝트 설명

**✅ 사거리의 차량 신호등과 보행자 신호등을 PLC와 HMI로 구현했습니다.**

- **신호 매커니즘 :**
    - 직진 좌회전 동시 신호가 있는 사거리 신호등
    - 임의의 차량 직좌 신호가 녹색일 때
        - 직진과 같은 방향의 우측 보행자 신호는 녹색
        - 나머지 모든 신호는 적색

<details>
<summary>메모리 할당</summary>
<div markdown="1">

1. **신호등 시퀀스 :**
        - 사거리의 도로 하나 당 6개의 2진 변수를 갖는 신호등이 필요
            - 총 24개의 신호등이 켜지는 시점을 8개의 시간대로 나눔
        - 1번 도로 녹색 → 4번 도로 녹색 순서로 반복
            ![1](https://github.com/jongsoo0603/codingOn/assets/98942866/dd18db51-6189-42ab-b776-205400f4808d)
            
    
1. **메모리 시퀀스 :**
    - 8개의 시점 마다 모든 변수에 직접 1 또는 0 입력 ❌
    - 각 시점마다 로컬 변수에 24바이트 값을 입력 해두고
        - 각 신호등이 해당 시점의 메모리에 접근 ⭕
            
            ![2](https://github.com/jongsoo0603/codingOn/assets/98942866/60b688cc-7786-4a39-9525-323fa25e6af1)
            

1. **로컬 변수 :**
    - 각 시점의 24바이트 2진수
        - →  10진수
            - → 초기값에 입력
                
                ![3](https://github.com/jongsoo0603/codingOn/assets/98942866/a1afddbb-8521-4657-b747-5ea2538c9ee9)

</div>
</details>


<details>
<summary>PLC 설계</summary>
<div markdown="1">

**설계 과정**
    
- ANY_MOVE 함수를 이용하여 메모리의 특정 위치에 미리 넣어 둔 값을 입력하도록 설계
- 8개의 타이머를 이용하여 순차적으로 값이 돌아가면서 입력되도록 설계

**간략화 설계도**

1. 5초 타이머
    
    ![4](https://github.com/jongsoo0603/codingOn/assets/98942866/05680b21-bc05-4a29-8f0c-48ebceb5530b)
    
2. 타이머 이후 할당된 메모리값 입력
    
    ![5](https://github.com/jongsoo0603/codingOn/assets/98942866/e3c3799f-9a5d-431d-9581-7a8d19434e44)
    
<details>
<summary>🔥 전체 PLC 설계도 🔥</summary>
<div markdown="1">

![6](https://github.com/jongsoo0603/codingOn/assets/98942866/c85cd340-46e6-4780-b58f-558e84c86e25)

</div>
</details>


</div>
</details>             

    
    
    
        

---

# 📺 시연 영상

- 녹색 신호 시점 (5초):
    - 차량 이동, 보행자 횡단
- 황색 신호 시점 (2초):
    - 차량 대기

[![Video Label](http://img.youtube.com/vi/IJV3wNb-aPw/0.jpg)](https://youtu.be/IJV3wNb-aPw?si=W7CFSIgcUoNS9okf)


---
---
---
  
# [보행자 기준 신호등](https://www.notion.so/8ec43837969441c19371690e7432eba9?pvs=4)

---

# **👆🏻프로젝트 개요**

- **개발 환경**
    - Windows
    - PLC
        - XG-5000
    - HMI
        - XP-Builder

- **개발 기간**
    - 2023/10/30 ~ 2023/11/02

- **회고**
    - 경험
        - PLC ↔ HMI 연동
        - PLC 활용 및 설계의 이해
        - HMI로 UI  활용
        - 100% PLC로 구현 ⭕
            - HMI 스크립트 활용 ❌
    - 보완 사항
        - 효율적인 PLC 설계
        - 불필요한 PLC 정리

---

# 💡 **프로젝트 설명**

**✅ 보행자 입장**에서의 횡단보도와 차선 신호등을 PLC와 HMI로 구현했습니다.

- **신호 매커니즘**
    
    보행자가 발판 누름
    
    &nbsp;&nbsp;&nbsp;&nbsp;<U>8초</U> 후 → 차선 <span style="color:orange">황색</span> 신호
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<U>2초</U> 후 → 차선  <span style="color:red">적색</span> 신호, 보행자 <span style="background-color:green">녹색</span> 신호,  <span style="background-color:gray">카운트 다운</span> 시작(20 부터)
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<U>10초</U> 후 → 보행자 <span style="background-color:green">녹색 점멸</span>
    
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<U>10초</U> 후→ 차량 <span style="color:green">녹색</span> 신호, 보행자 <span style="background-color:red">적색</span> 신호 유지
    

<details>
<summary>PLC 설계</summary>
<div markdown="1">

1. 각 시점의 타이머 생성
        
    ![1](https://github.com/jongsoo0603/codingOn/assets/98942866/eff52f26-ac84-4ba9-a4ae-601cd6be9b2b)
2. 해당 시점의 타이머가 끝나는 노드에  연결 된 메모리 주소에 ON / OFF 입력 및 필요한 기능 수행
    
    ![2](https://github.com/jongsoo0603/codingOn/assets/98942866/2a179913-c240-450a-a15a-3bf1728f4d7a)
    
3. 발판 입력 시 카운트 다운 변수 초기화, 보행자 녹색 점멸 기능
    
    ![3](https://github.com/jongsoo0603/codingOn/assets/98942866/46f0b23a-ad47-46c3-88b1-84a6dba33e06)

</div>
</details>

---

# 📺 시연 영상

[![Video Label](http://img.youtube.com/vi/ySnZ2HSlHJg/0.jpg)](https://youtu.be/ySnZ2HSlHJg?si=sH-4o2vJdioA2NOH)

---
