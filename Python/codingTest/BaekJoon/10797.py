import sys
sys.stdin.readline

num = int(input())
arr = list(map(int, input().split()))
res = 0
for i in arr:
    if num == i:
        res += 1
print(res)
