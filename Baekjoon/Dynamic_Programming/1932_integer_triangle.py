# https://www.acmicpc.net/problem/1932
# DP
import sys

input = sys.stdin.readline
N = int(input())
D = []

for _ in range(N):
    D.append(list(map(int, input().split())))

for i in range(1, N):
    for j in range(len(D[i])):
        if j == 0:
            D[i][0] += D[i - 1][0]
        elif i == j:
            D[i][j] += D[i - 1][j - 1]
        else:
            D[i][j] += max(D[i-1][j-1], D[i-1][j])

print(max(D[N - 1]))
