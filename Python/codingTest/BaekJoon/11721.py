import sys
input = sys.stdin.readline

word = input()

i = 0
while True:
    print(word[i: i + 10])
    i += 10
    if i >= len(word):
        print(word[i:-1])
        break
