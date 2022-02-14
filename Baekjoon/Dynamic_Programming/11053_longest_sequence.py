# https://www.acmicpc.net/problem/11053
# DP, LIS

N = int(input())
sequence = list(map(int, input().split()))
D = [1 for _ in range(N)]

for i in range(0, N):
    for j in range(0, i):
        if sequence[i] > sequence[j]:
            D[i] = max(D[i], D[j] + 1)
print(max(D))
