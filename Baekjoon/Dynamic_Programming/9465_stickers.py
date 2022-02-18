# https://www.acmicpc.net/problem/9465
# DP

# OX
# XO    (한 칸 대각선)
# 또는
# OXX   (두 칸 대각선)
# XXO


def solve():
    n = int(input())
    data = [[0], [0]]
    for i in range(2):
        data[i].extend(list(map(int, input().split())))

    for i in range(1, n + 1):
        pass


for _ in range(int(input())):
    solve()
