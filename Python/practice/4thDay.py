"""
### 실습3 ###
name = input("이름을 입력하세요. : ")
pw =  input("비밀번호를 입력하세요 : ")

f = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/member.txt", "r")
member = f.readlines()
f.close()

if name + " " + pw + "\n" in member:
    print("로그인 성공")
    phoneNum = input("전화번호를 입력하세요. : ")
    
    f2 = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/member_tel.txt", "r")
    phoneInfo = f2.readlines()
    f2.close()
    
    check = False
    idx = 0
    for info in phoneInfo:
        infoName = info.split()
        if name == infoName[0]: # 이름이 이미 존재 하는 사람이라면
            print("이름이 이미 존재하므로 전화번호를 수정합니다.")
            check = True
            phoneInfo[idx] = name + " " + phoneNum + "\n"
            f1 = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/member_tel.txt", "w")
            for i in phoneInfo:
                print(i)
                f1.write(i)
            print("전화번호 수정 완료")
        idx += 1
    
    if check == False: # 이름이 이미 존재하는 사람이 아니라면
        print("이름이 없으므로 전화번호를 저장합니다.")
        f1 = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/member_tel.txt", "a")
        f1.write(name + " " + phoneNum + "\n")
        print("전화번호 저장 완료")
    f1.close()

else:
    print("로그인 실패")


# idx = -1
    # for i in range(len(phoneInfo)):
    #     if name in phoneInfo[i]:
    #         idx = i
    
    # if idx != -1: # 이미 존재 하는 사람이라면
    #     print("이름이 이미 존재하므로 전화번호를 수정합니다.")
    #     phoneInfo[i] = name + " " + phoneNum + "\n"
    #     f1 = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/member_tel.txt", "w")
    #     for i in phoneInfo:
    #         f1.write(i)
    #     print("전화번호 수정 완료")
    # else: # 이미 존재하는 사람이 아니라면
    #     print("이름이 없으므로 전화번호를 저장합니다.")
    #     f1 = open("/Users/shinjongsoo/Desktop/codingOn/Python/practice/member_tel.txt", "a")
    #     f1.write(name + " " + phoneNum + "\n")
    #     print("전화번호 저장 완료")
    # f1.close()


### 실습 ###
while True:
    try:
        inputINT = int(input("숫자 입력 : "))
    except ValueError:
        print("정수가 아님!!")
    else:
        print("정수 입력 성공 :", inputINT)
        break
"""

### 실습 ###
import numpy as np

# 10개의 0으로 채워진 array를 만들고 출력
n1 = np.zeros(10)
print("1 :", n1)

# 1번에서 만들어지 arra에서 5번째 값을 1로 바꾸고 출력
n1[4] = 1
print("2 :\n", n1)

# 10부터 30까지 수로 이루어진 array를 만들고 출력
print("3 :\n", np.arange(10, 31))

# 0부터 99까지의 난수로 이루어진 2 X 2 array 만들고 출력
print("4 :\n", np.random.randint(100, size=(2, 2)))

# 0부터 1사이의 난수로 이루어진 2 X 2 array를 만들고 출력
print("5 :\n", np.random.rand(2, 4))


n2 = np.arange(35, 75).reshape(10, 4)
print("6 :\n", n2)

print("7 :")
for i in range(len(n2) - 1, -1, -1):
    print(n2[i])
    
print("8 :\n", n2[1:- 1, 2:])

print("9\n", n2[:, -1:].flatten())

print("9-1 :\n", n2[:, -1:])

print("10 :\n", n2[::-1, -1:])

n3 = np.random.randint(1, 51, size=(5, 6))
print("11 :\n", n3)

print("짝수 :\n", n3[n3 % 2 == 0])

