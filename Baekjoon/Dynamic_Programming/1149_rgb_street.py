# https://www.acmicpc.net/problem/1149
# DP

N = int(input())

costs = []

for _ in range(N):
    rgb = list(map(int, input()))
    costs.append(rgb)
