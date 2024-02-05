import sys
sys.stdin.readline

arr = []
for i in range(3):
    arr.append(int(input()))


if arr[0] + arr[1] + arr[2] == 180:
    if arr[0] == arr[1] and arr[0] == arr[2]:
        print("Equilateral")
    elif arr[0] == arr[1] or arr[0] == arr[2] or arr[1] == arr[2]:
        print("Isosceles")
    else:
        print("Scalene")

else:
    print("Error")
