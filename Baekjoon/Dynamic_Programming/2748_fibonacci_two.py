# https://www.acmicpc.net/problem/2748
# DP

N = int(input())
D = [0, 1, 1]
if N >= 3:
    for i in range(3, N + 1):
        D.append(D[i - 1] + D[i - 2])

print(D[N])
