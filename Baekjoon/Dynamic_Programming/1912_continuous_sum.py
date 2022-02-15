# https://www.acmicpc.net/problem/1912
# DP

N = int(input())
data = list(map(int, input().split()))
D = [0 for _ in range(N)]
D[0] = data[0]

for i in range(1, N):
    if D[i - 1] > 0:
        D[i] = D[i - 1] + data[i]
    else:
        D[i] = data[i]
print(max(D))
