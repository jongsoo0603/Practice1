import sys
input = sys.stdin.readline

ex = list(map(int, input().split()))
ex.sort()
ex = list(map(str, ex))

print(" ".join(ex))
