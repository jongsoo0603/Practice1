import sys
input = sys.stdin.readline

word = input().rstrip()

result = True
for i in range(len(word) // 2):
    if word[i] != word[-(i+1)]:
        result = False
        break

print(int(result))
