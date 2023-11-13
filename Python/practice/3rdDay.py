"""
### 실습 1 ###
score = {"Alice" : 85, "Bob" : 90, "Charlie" : 95}
print("2 :", score)

score["David"] =  80
print("3 :", score)

score["Alice"] = 88
print("4 :", score)

del(score["Bob"])
print("5 :", score)

print("6 :")
for i in score:
    print("key : " + i + ", value : " + str(score[i]))

def check_machine():
    return print(vending_machine,"\n\n")

def is_drink(drink):
    if drink in vending_machine :
        printing = "\n" + drink + "드릴게요\n" + drink + " 제거 완료"
        vending_machine.remove(drink)
    else :
        printing = drink + "는 지금 없네요"
    return print(printing)

def add_drink(add):
    vending_machine.append(add)
    vending_machine.sort()
    return print(add + " 추가 완료")

def remove_drink(delete):
    if delete in vending_machine:
        vending_machine.remove(delete)
        return print(delete + " 제거 완료")
    else:
        return print(delete + "는 지금 없네요")

vending_machine = ["게토레이", "게토레이", "레쓰비", "생수", "생수", "생수", "이프로"]
while True :
    user = int(input("사용자 입력 (소비자 = 1, 주인 = 2) : "))
    if user == 1:
        drink = input("마시고 싶은 음료 : ")
        is_drink(drink)
    elif user == 2:
        select = int(input("기능 입력 (추가 = 1, 삭제 = 2) : "))
        if select == 1:
            add = input("추가할 음료 : ")
            add_drink(add)
        elif select == 2:
            delete = input("삭제할 음료 : ")
            remove_drink(delete)
        else:
            print("잘못된 값을 입력하셨습니다.")    
    else:
        print("잘못된 값을 입력하셨습니다.")
        
    print("\n====================RESTART\n재고 현황 :")
    check_machine()



### 실습 2 ###
def fibonacci(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

print(fibonacci(int(input("피보나치 수열 인자 입력 : "))))


### class 실습1 ###
class Calculator:
    def __init__(self, A, B):
        self.a = A
        self.b = B
    def add(self):
        return self.a + self.b
    def sub(self):
        return self.a - self.b
    def mul(self):
        return self.a * self.b
    def div(self):
        return self.a / self.b

c = Calculator(4, 2)

print("add :",c.add())
print("sub :",c.sub())
print("mul :",c.mul())
print("div :",c.div())




### 실습1 ###
class Supermarket:
    count = 0
    def __init__(self, location, name, product, customer):
        self.l = location
        self.n = name
        self.p = product
        self.c = customer
        Supermarket.count += 1
        
    def print_location(self):
        return print("가게 위치 :", self.l)
    
    def change_category(self, cp):
        self.p = cp
        
    def show_list(self):
        return print("파는 물건 :", self.p)
    
    def enter_customer(self):
        self.c =  str(int(self.c) + 1)
    
    def show_info(self):
        return print("가게 이름 :" + self.n + ", 위치 : " + self.l + ", 파는 물건 : " + self.p + ", 손님 수 : " + self.c)
    
    def show_supermarket_cout(self):
        return print("가게 개수 :", self.count)
    
    
super = Supermarket("대흥", "나이키", "옷", "3")
super.show_info()
super.print_location()
super.show_list()
super.change_category("신발")
super.enter_customer()
super.show_info()

super.show_supermarket_cout()


### 실습 3 ###
class Calculator():
    def __init__(self):
        self.value = 100
        
    def sub(self, value):
        self.value -= value

class MinLimitCalculator(Calculator):
    def sub(self, value):
        if value > -1:
            self.value = value
        else:
            self.value = 0
            
cal = MinLimitCalculator()
cal.sub(20)
cal.sub(90)
print(cal.value)


import calc_module

print(calc_module.add(4, 2))
print(calc_module.sub(4, 2))
print(calc_module.mul(4, 2))
print(calc_module.div(4, 2))

import math
print(math.floor(3.141))

from math import *
print(floor(3.141))

### 실습 ###
import random

arr = []
for _ in range(4):
    arr.append(random.randint(1,100))
    
print(sorted(arr))


### 실습 ###
from random import *

randNum = randint(1, 10)

while True:
    num = int(input("숫자를 맞춰보세요"))
    if randNum == num:
        print("맞았어요! 랜덤 숫자는", randNum, "입니다!")
        break
    else:
        print("땡!")


### 실습 ###
from random import *
lotto = list(range(1, 46))
print(sample(lotto, k = 6))


f = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/test.txt", "w")
f.write("Hello World \n")
f.close

f3 = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/test.txt", "a")
f3.write("Hello World22 \n")
f3.close


f2 = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/test.txt", "r")
print(f2.read())
f2.close


"""
### 파일 입출력 실습1 ###
string = ""
for _ in range(3):
    string += input("이름 비밀번호 : ") + "\n"
f1 = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/test.txt", "w")
f1.write(string)
f1.close

f2 = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/test.txt", "r")
print(f2.read())
f2.close