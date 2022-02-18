# https://www.acmicpc.net/problem/11052
# DP
import copy

N = int(input())
data = [0]
data.extend(list(map(int, input().split())))
D = copy.deepcopy(data)
for i in range(2, N + 1):
    for j in range(1, i):
        D[i] = max(D[i], D[i - j] + D[j])

print(D[N])
