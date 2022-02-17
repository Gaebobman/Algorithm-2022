# https://www.acmicpc.net/problem/2193
# DP
N = int(input())
# 메모리 초과남, 그냥 갯수만 세자
# D = [[] for _ in range(N)]
# D[0].append("1")
# for i in range(1, N):
#     for x in D[i - 1]:
#         if x % 2 == 0:
#             D[i].append(x << 1)
#             D[i].append(x << 1 + 0b1)
#         else:
#             D[i].append(x << 1)
# print(len(D[N - 1]))
D = [0, 1, 1]
for i in range(3, N + 1):
    D.append(D[i - 1] + D[i - 2])
print(D[N])
