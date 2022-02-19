# https://www.acmicpc.net/problem/9465
# DP

# OX
# XO    (한 칸 대각선)
# 또는
# OXX   (두 칸 대각선)
# XXO

def solve():
    n = int(input())
    data = []
    for i in range(2):
        data.append(list(map(int, input().split())))
    dp = [[0] * (n + 1) for _ in range(2)]
    dp[0][0] = data[0][0]
    dp[1][0] = data[1][0]
    if n >= 2:
        dp[0][1] = data[0][1] + dp[1][0]
        dp[1][1] = data[1][1] + dp[0][0]
        for i in range(2, n):
            dp[0][i] = data[0][i] + max(dp[1][i - 1], dp[1][i - 2])
            dp[1][i] = data[1][i] + max(dp[0][i - 1], dp[0][i - 2])
    print(max(dp[0][n - 1], dp[1][n - 1]))


for _ in range(int(input())):
    solve()
