# https://www.acmicpc.net/problem/1149
# DP

N = int(input())

costs = []

for _ in range(N):
    rgb = list(map(int, input().split()))
    costs.append(rgb)

for i in range(1, N):
    costs[i][0] = min(costs[i - 1][1], costs[i - 1][2]) + costs[i][0]
    costs[i][1] = min(costs[i - 1][0], costs[i - 1][2]) + costs[i][1]
    costs[i][2] = min(costs[i - 1][0], costs[i - 1][1]) + costs[i][2]

print(min(costs[N - 1]))

