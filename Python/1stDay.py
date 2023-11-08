
print("|\_/|")
print("|q p|   /}")
print('( 0 )"""\\')
print('|"^"`    |')
print("||_/=\\\__|\n")
"""
print(3 / 2)
print(3 // 2, "\n")

name = input("이름을 입력하세요. ")
age = input("나이를 입력하세요. ")
print("안녕하세요! ", name,"님 (",age,")세", sep="")

print()
name = input("이름을 입력하세요. ")
birth = input("태어난 년도를 입력하세요. ")
year = input("올해 연도를 입력하세요. ")
print("올해는 ",year,"년, ", name,"님의 나이는 ",int(year)-int(birth) + 1,"세 입니다.", sep="")


a = int(input("(1) 입력 : "))
b = input("(2) 입력 : ")
print("\n(3) :",a * int(b[2]))
print("(4) :",a * int(b[1]))
print("(5) :",a * int(b[0]))
print("(6) :",a * int(b))

c = ["1", "2", "1"]
print(c.index("1"))
print(c.index("1", c.index("1") + 1))


rainbow = ["red", "orange", "yellow", "green", "blue", "indigo", "purple"]
print("1.", rainbow[2])
print("2.", sorted(rainbow))
rainbow.append("black")
print("3.", rainbow)
del rainbow[2:6]
print("4.", rainbow)


num = int(input("숫자 입력 : "))
if num % 2 == 0 :
  print("짝수!")
else :
  print("홀수!")


score = int(input("점수 입력 : "))
if -1 < score < 60 :
  print("E")
elif score < 70 :
  print("D")
elif score < 80 :
  print("C")
elif score < 90 :
  print("B")
elif score < 101:
  print("A")
else :
  print("잘못입력하셨습니다.")
"""

age = int(input("나이 입력 : "))
pay = input("카드 or 현급 입력 : ")

if age > 74 or age < 8:
  price = 0
elif age < 14 :
  price = 450
elif age < 20 :
  if pay == "카드" :
    price = 720
  else :
    price = 1000
elif age < 75 :
  if pay == "카드" :
    price = 1200
  else :
    price = 1300

print(f"{age}세의 {pay}요금은 {price}원 입니다.")
