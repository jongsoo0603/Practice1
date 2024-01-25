# [따릉이 데이터 분석](https://www.notion.so/ab1640ff68224634b7dba0b88dac7498?pvs=4)

---

# 👆🏻프로젝트 개요

<aside>
✅ 빅데이터를 비교 분석하여 ‘왜’ 그런 데이터가 나왔는지 인과관계를 추측

- 주요 분석 사항

  - [이용률 ←→ 기온](https://github.com/jongsoo0603/codingOn/assets/98942866/0d9753bc-8c08-4244-a072-9ccdf865020c)
  - [이용률 ←→ 강수량](https://github.com/jongsoo0603/codingOn/assets/98942866/974c987e-ba85-4f88-8927-2a8c01122c8a)
  - [이용률 ←→ 대여소 수](https://github.com/jongsoo0603/codingOn/assets/98942866/54ec8860-d88b-4df3-8a14-5ac231058540)
  - [운동량 ←→ 연령대](https://github.com/jongsoo0603/codingOn/assets/98942866/2d9f876c-5d59-44ec-9e13-9c4c57bb5fd3)

- 데이터
  - 따릉이 대여 데이터
    - [서울열린데이터광장- 서울시공공자전거이용정보(일별)](http://data.seoul.go.kr/dataList/OA-13252/F/1/datasetView.do)
    - 2023년1월1일~6월30일
  - 따릉이 대여소 데이터
    - [서울열린데이터광장- 서울시공공자전거대여소정보](http://data.seoul.go.kr/dataList/OA-15246/F/1/datasetView.do)
    - 2023년06월
  - 날씨 데이터
    - [공공데이터포털- 기상청\_지상(종관, ASOS)일자료조회서비스](https://www.data.go.kr/data/15059093/openapi.do)
    - 2023년1월1일~ 6월30일
  - 체력 측정 데이터 - [국가통계포털- 지역별,연령별체력,체격측정결과:서울(남자)](https://kosis.kr/statHtml/statHtml.do?orgId=113&tblId=DT_113_STBL_1025785&conn_path=I2), ["(여자](https://kosis.kr/statHtml/statHtml.do?orgId=113&tblId=DT_113_STBL_1025783&conn_path=I2) - 2017년
  </aside>

### 사용 기술 및 라이브러리

- Python
- Pandas - 데이터 가공
- Seaborn - 시각화
- Pyplot - 시각화
- Folium - 지도 출력

### 개발 환경

- Mac OS
- Visual Studio Code
- Jupyter Notebook
- Git

### 개발 기간

- 2023/11/21 ~ 2023/11/30

### 회고

- 경험
  - 주제에 맞는 빅데이터 수집
  - 필요한 정보를 알맞게 전처리
- 보완 사항
  - 대여소 실시간 잔여 자전거 현황
    - 맵에 단순히 따릉이 대여소를 출력하는 것이 아닌 현황까지 원했으나 크롤링을 막아놓음
  - 이용률이 높은 자치구의 이유
    - 이용률이 높은 구에 대여소도 많은 것을 확인 했으나 해당 구가 이용률이 높은 이유는 미흡

---

# 📺 결과

![1](https://github.com/jongsoo0603/codingOn/assets/98942866/0d9753bc-8c08-4244-a072-9ccdf865020c)
![2](https://github.com/jongsoo0603/codingOn/assets/98942866/974c987e-ba85-4f88-8927-2a8c01122c8a)
![3](https://github.com/jongsoo0603/codingOn/assets/98942866/54ec8860-d88b-4df3-8a14-5ac231058540)
![4](https://github.com/jongsoo0603/codingOn/assets/98942866/2d9f876c-5d59-44ec-9e13-9c4c57bb5fd3)

---

# 📃 [발표 PPT](https://drive.google.com/file/d/10MRiGzbKs2pJzfxK0QKlAsM2vDXwWo1J/view?usp=share_link)

---
