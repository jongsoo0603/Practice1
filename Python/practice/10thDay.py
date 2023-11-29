from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager
from openpyxl import Workbook
from time import sleep

search = input("검색할 상품 입력 : ")

chrome_options = Options()
chrome_options.add_experimental_option("detach", True)

service = Service(executable_path=ChromeDriverManager().install())
driver = webdriver.Chrome(service=service, options=chrome_options)

driver.get("https://shopping.naver.com/home")

firstClick = driver.find_element(By.CLASS_NAME, "_searchInput_search_input_QXUFf")
firstClick.click()

searchInput = driver.find_element(By.CLASS_NAME, "_searchInput_search_text_3CUDs")
searchInput.send_keys(search)
searchInput.send_keys(Keys.RETURN)

for _ in range(5):
    sleep(0.1)
    driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")


adProducuts= driver.find_elements(By.CSS_SELECTOR, ".adProduct_info_area__dTSZf")  #광고 상품 공통 클래스
normalProducts = driver.find_elements(By.CSS_SELECTOR, ".product_info_area__xxCTi") #일반 상품 공통 클래스

wb = Workbook()
ws = wb.active

# 시트 이름 설정
ws.title = search + " 네이버 쇼핑 검색 리스트.xlsx"

ws.append([ws.title,"",""])
ws.append(["","",""])
ws.append(["상품명","가격","주소"])

# print("광고 상품")
ws.append(["","",""])
ws.append(["광고 상품","",""])
for product in adProducuts:
    info = product.find_element(By.CSS_SELECTOR, ".adProduct_link__NYTV9") 
    name = info.get_attribute("title")
    link = info.get_attribute("href")
    if product.find_element(By.CSS_SELECTOR, ".adProduct_price_area__yA7Ad").text != "판매중단":
        price = product.find_element(By.CSS_SELECTOR, ".price_num__S2p_v").text
    else:
        price = "판매중단"
    # print(name, price, link)
    ws.append([name, price, link])
    

# print("일반 상품")
ws.append(["","",""])
ws.append(["일반 상품","",""])
for product in normalProducts: #일반 상품
    info = product.find_element(By.CSS_SELECTOR, ".product_link__TrAac") 
    name = info.get_attribute("title")
    link = info.get_attribute("href")
    if product.find_element(By.CSS_SELECTOR, ".product_price_area__eTg7I").text != "판매중단":
        price = product.find_element(By.CSS_SELECTOR, ".price_num__S2p_v").text
    else:
        price = "판매중단"
    # print(name, price, link)
    ws.append([name, price, link])

# 엑셀 저장
wb.save(ws.title)