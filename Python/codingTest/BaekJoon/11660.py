n, m = map(int, input().split())
n = 4

original = []


for i in range(n):
    original.append(list(map(int, input("입력: ").split())))


# for i in range(n):
#     for j in range(n):
#         if i != 0 and j != 0:
#             sum[i][j] = original[i][j-1] + original[i-1][j] \
#                 - original[i-1][j-1] + original[i][j]
#         elif i == 0

print(sum)
