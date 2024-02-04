import sys
input = sys.stdin.readline

N = input().replace("\n", "")

if int(N) < 10:
    N = "0" + N

new, res = 0, 0
a = N[0]
b = N[-1]

while N != new:
    sum = int(a) + int(b)
    new = b + str(sum)[-1]
    res += 1
    a = new[0]
    b = new[-1]
print(res)
