# https://www.acmicpc.net/problem/11727
# DP
MOD = 10007
N = int(input())

D = [0 for _ in range(1001)]
D[1] = 1
D[2] = 3

for i in range(3, N + 1):
    D[i] = (D[i - 1] + D[i - 2] * 2) % MOD
print(D[N])
