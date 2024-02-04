import sys
imput = sys.stdin.readline

n = int(input())


result = list(input())
for i in range(n-1):
    text = list(input())
    for j in range(len(text)):
        t = text[j]
        if (result[j] != t) or (t.isalpha() != True and t != "."):
            result[j] = "?"

print(''.join(result))
