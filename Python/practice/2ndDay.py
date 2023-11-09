"""
### 과제2 ###
n = int(input("정수 입력 : "))
arr = []

for i in range(1, n+1) :
    arr.append(i)

print("\n1) 정수 n을 입력받아 1부터 n까지의 정수를 포함하는 리스트 만들기 : \n", arr)

print("\n\n2-1) 슬라이싱을 사용해서 짝수 만 출력하기 : \n", arr[::2])

print("\n\n2-2) 슬라이싱을 사용해서 홀수 만 출력하기 : \n", arr[1::2])


### 과제3 ###
vending_machine = ["게토레이", "게토레이", "레쓰비", "생수", "생수", "생수", "이프로"]
while True :
    user = int(input("사용자 입력 (소비자 = 1, 주인 = 2) : "))
    if user == 1:
        drink = input("마시고 싶은 음료 : ")
        if drink in vending_machine :
            print("\n" + drink + "드릴게요\n" + drink + " 제거 완료")
            vending_machine.remove(drink)
        else :
            print(drink + "는 지금 없네요")    
    elif user == 2:
        select = int(input("기능 입력 (추가 = 1, 삭제 = 2) : "))
        if select == 1:
            
            add = input("추가할 음료 : ")
            vending_machine.append(add).sort()
            vending_machine.sort()
            print(add + " 추가 완료")
        elif select == 2:
            delete = input("삭제할 음료 : ")
            if delete in vending_machine:
                vending_machine.remove(delete)
                print(delete + " 제거 완료")
            else:
                print(delete + "는 지금 없네요")    
        else:
            print("잘못된 값을 입력하셨습니다.")    
    else:
        print("잘못된 값을 입력하셨습니다.")
        
    print("\n====================RESTART\n재고 현황 :" , vending_machine , "\n\n")


### 실습1 ###
sum = 0
osum = 0

n = int(input("정수 입력 : "))

for i in range(1,n+1):
    sum += i
    if(i % 2 == 1):
        osum += i
        
gsum = n*(n+1)//2

print("총 합 =",sum)
print("홀수 합 =",osum)
print("포문 안쓰고 총 합 =",gsum)


### 실습2 ###
sec = int(input("몇 초? : "))

for i in range(sec, 0, -1):
    print(i, end=" ")
    
print("발사!")


### 실습3 ###
x = int(input("몇 단을 출력할까요?"))
for i in range(1, 10):
    print(x, "*", i, "=", x * i)


### 실습4 ###
x = int(input("몇 단을 출력할까요? "))
# 1번
for i in range(1, x + 1):
    print("*" * i)
# 2번
for i in range(x-1, -1, -1):
    print(" " * i, "*" * (x - i))
# 3번
for i in range(x-1, -1, -1):
    print(f'{" " * i}{"*" * (x - i)}{"*" * (x - i - 1)}')

### 실습5 ###
string = input("숫자 여러 개 입력 : ").split()
list =[]

for i in range(len(string)):
    list.append(int(string[i]))
    
maximum = max(list)
minimum = min(list)
list.remove(max(list))
list.remove(min(list))
avg = sum(list) / len(list)

print("최대값 = " + str(maximum) + ", 최소값 = " + str(minimum) + ", 둘 뺀 평균 = " + str(avg))

arr1 = ["b", "s", "c"]
arr2 = [ "b", "c", "d", "e", "c", "s"]

res = 0
for i in arr2:
    if i in arr1:
        res += 1

print(res)
"""


"""
문제
총 N개의 문자열로 이루어진 집합 S가 주어진다.
입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 것이 총 몇 개인지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 문자열의 개수 N과 M (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 10,000)이 주어진다. 
다음 N개의 줄에는 집합 S에 포함되어 있는 문자열들이 주어진다.
다음 M개의 줄에는 검사해야 하는 문자열들이 주어진다.
입력으로 주어지는 문자열은 알파벳 소문자로만 이루어져 있으며, 길이는 500을 넘지 않는다. 집합 S에 같은 문자열이 여러 번 주어지는 경우는 없다.

출력
첫째 줄에 M개의 문자열 중에 총 몇 개가 집합 S에 포함되어 있는지 출력한다.

예제 입력 1 
5 11
baekjoononlinejudge
startlink
codeplus
sundaycoding
codingsh
baekjoon
codeplus
codeminus
startlink
starlink
sundaycoding
codingsh
codinghs
sondaycoding
startrink
icerink

예제 출력 1 
4
"""

"""
import sys
input = sys.stdin.readline
N, M = map(int, input().split())

arr1 = set()
for _ in range(N):
    arr1.add(input())

res = 0
for _ in range(M):
    name = input()
    if name in arr1:
        res += 1

print(res)
"""