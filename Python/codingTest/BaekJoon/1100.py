import sys
input = sys.stdin.readline

sum = 0
for i in range(8):
    line = input()
    for j in range(8):
        jj = j % 2
        if i % 2 == 1:
            if (jj == 1) and line[j] == "F":
                sum += 1
        else:
            if (jj == 0) and line[j] == "F":
                sum += 1
print(sum)
