import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    h, w, n = map(int, input().split())

    b = str((n // h) + 1)

    if (n % h) == 0:
        a = str(h)
        b = str(int(b)-1)
    else:
        a = str((n % h))

    if int(b) < 10:
        b = "0" + b

    print(a + b)
