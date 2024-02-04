import sys
input = sys.stdin.readline

t = int(input())

arr = []
for i in range(t):
    arr.append(list(map(int, input().split())))

for i in arr:
    a = i[0] % 10
    b = i[1]

    if a == 0:
        print(10)
    elif a == 1 or a == 5 or a == 6:
        print(a)
    elif a == 4:
        if b % 2 == 0:
            print(6)
        else:
            print(a)
    elif a == 9:
        if b % 2 == 0:
            print(1)
        else:
            print(a)
    elif a == 2:
        bb = b % 4
        if bb == 0:
            print(6)
        elif bb == 1:
            print(2)
        elif bb == 2:
            print(4)
        else:
            print(8)
    elif a == 3:
        bb = b % 4
        if bb == 0:
            print(1)
        elif bb == 1:
            print(3)
        elif bb == 2:
            print(9)
        else:
            print(7)
    elif a == 7:
        bb = b % 4
        if bb == 0:
            print(1)
        elif bb == 1:
            print(7)
        elif bb == 2:
            print(9)
        else:
            print(3)
    else:
        bb = b % 4
        if bb == 0:
            print(6)
        elif bb == 1:
            print(8)
        elif bb == 2:
            print(4)
        else:
            print(2)
# 1 : 1
# 2 : 2, 4, 8, 6
# 3 : 3, 9, 7, 1,
# 4 : 4, 6
# 5 : 5
# 6 : 6
# 7 : 7, 9, 3, 1
# 8 : 8, 4, 2, 6
# 9 : 9, 1
