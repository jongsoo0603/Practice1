
from bs4 import BeautifulSoup
import requests

# nSearch = input("검색어 입력 : ")
# pages = int(input("페이지 수 : "))
# #print("검색어 :", search, "\n페이지 수 : ", pages)
# print("\n", "=" * 100, "\n")

# for i in range(pages):
#     print(str(i + 1), "페이지")
#     nAddress = "https://search.naver.com/search.naver?sm=tab_hty.top&where=news&query=" + nSearch + "&start=" + str(i) + "1"
#     news = requests.get(nAddress)
#     naverNews = news.text
#     nSoup = BeautifulSoup(naverNews, 'html.parser')

#     for j in range(0,10):
#         print(str(j + 1), ":", nSoup.select(".news_tit")[j]['title'], nSoup.select(".news_tit")[j]['href'])
#     print("\n\n", "=" * 100, "\n")
    


# from openpyxl import Workbook, load_workbook

# # 엑셀 만들기
# wb = Workbook()
# # # 엑셀 불러오기
# # wb = load_workbook('./삼다수 G마켓 검색 리스트.xlsx')

# # 워크시드 만들기
# ws = wb.active
# ws.title = "gMarketData"

# gSearch = input("검색어 입력 : ")
# gAddress = "https://browse.gmarket.co.kr/search?keyword=" + gSearch
# gRequests = requests.get(gAddress)
# gMarket = gRequests.text
# gSoup = BeautifulSoup(gMarket, 'html.parser')

# gLength = len(gSoup.select("span.text__item"))

# exelName = gSearch + " G마켓 검색 리스트.xlsx"
# ws.append([exelName,"",""])
# ws.append(["","",""])
# ws.append(["상품명", "가격", "주소"])

# for i in range(gLength):
#     gName = gSoup.select("div.box__item-title > span > a > span.text__item")[i].text
#     gPrice = gSoup.select("div.box__item-price > div > strong")[i].text
#     gLink = gSoup.select("div.box__item-title > span > a")[i]["href"]
#     ws.append([gName, gPrice, gLink])
    
# # 엑셀 저장

# wb.save(exelName)



from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By

chrome_options = Options()
chrome_options.add_experimental_option("detach", True)

service = Service(executable_path=ChromeDriverManager().install())
driver = webdriver.Chrome(service=service, options=chrome_options)

# # 해당 주소로 이동
# driver.get("https://www.naver.com")

# # 클래스 찾아서 클릭
# login = driver.find_element(By.CLASS_NAME, "MyView-module__my_login___tOTgr")
# login.click()


# id = driver.find_elements(By.CLASS_NAME, "input_text")[0]
# id.click()
# id.send_keys("gi62809")

# pw = driver.find_elements(By.CLASS_NAME, "input_text")[1]
# pw.click()
# pw.send_keys("qwer*963.")

# # login_btn = driver.find_element(By.CLASS_NAME, "btn_login_wrap")
# # login_btn.click()


driver.get("https://tcmssso.bu.ac.kr/svc/tk/Auth.eps?ac=Y&RelayState=%2Fexsignon%2Fsso%2Fsso_loginuser.jsp&ifa=N&id=bu_tcms&")

id = driver.find_elements(By.CLASS_NAME, "join_row")[0]
id.click()
id.send_keys("20172346")

pw = driver.find_elements(By.CLASS_NAME, "join_row")[1]
pw.click()
pw.send_keys("gi9541700@")


login_btn = driver.find_element(By.CLASS_NAME, "btn_login")
login_btn.click()

