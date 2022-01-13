# https://www.acmicpc.net/problem/11724
from collections import deque

N, M = map(int, input().split())
graph = [[0] * (N + 1) for _ in range(N + 1)]
visited = [False] * (N + 1)

for _ in range(M):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1




