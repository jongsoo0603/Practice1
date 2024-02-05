import sys
input = sys.stdin.readline


word = list(input().replace("\n", ""))
alhpa = list(range(97, 123))
res = ["0"] * 26


for i in word:
    index = alhpa.index(ord(i))
    res[index] = str(int(res[index]) + 1)

print(" ".join(res))
# 아스키코드 a:97 - z:122
# 97-122 : 26개
