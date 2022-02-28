# https://www.acmicpc.net/problem/7568
# Brute forcing
import sys

input = sys.stdin.readline
N = int(input())
data = []
for _ in range(N):
    weight, height = map(int, input().split())
    data.append([weight, height, 1])

for i in range(N):
    for j in range(N):
        if data[i][0] < data[j][0] and data[i][1] < data[j][1]:
            data[i][2] += 1

for i in range(N):
    print(data[i][2], end=' ')
