import sys
sys.stdin.readline


resX, resY = map(int, input().split())
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())

if resX == x1:
    resX = x2
elif resX == x2:
    resX = x1

if resY == y1:
    resY = y2
elif resY == y2:
    resY = y1

print(str(resX), str(resY))
