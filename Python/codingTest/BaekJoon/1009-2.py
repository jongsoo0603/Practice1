import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    a = a % 10

    if a == 0:
        print(10)
    elif a == 1 or a == 5 or a == 6:
        print(a)
    elif a == 4 or a == 9:
        if b % 2 == 0:
            print((a ** 2) % 10)
        else:
            print(a)
    else:
        if b % 4 == 0:
            print(a**4 % 10)
        else:
            print(a ** (b % 4) % 10)

# 1 : 1
# 2 : 2, 4, 8, 6
# 3 : 3, 9, 7, 1,
# 4 : 4, 6
# 5 : 5
# 6 : 6
# 7 : 7, 9, 3, 1
# 8 : 8, 4, 2, 6
# 9 : 9, 1
