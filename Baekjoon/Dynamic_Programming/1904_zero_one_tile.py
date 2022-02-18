# https://www.acmicpc.net/problem/1904
# DP
MOD = 15746
N = int(input())
D = [0, 1, 2]

for i in range(3, N + 1):
    D.append((D[i - 1] + D[i - 2]) % MOD)

print(D[N])
