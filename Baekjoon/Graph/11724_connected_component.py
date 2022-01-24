# https://www.acmicpc.net/problem/11724
import sys
from collections import deque

input = sys.stdin.readline
N, M = map(int, input().split())
visited = [False] * (N + 1)

graph = [[] for _ in range(N + 1)]

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)


def bfs(start):
    q = deque([start])
    visited[start] = True
    while q:
        v = q.popleft()
        for node in graph[v]:
            if not visited[node]:
                visited[node] = True
                q.append(node)

    return 1


result = 0

for i in range(1, N + 1):
    if not visited[i]:
        result += bfs(i)


print(result)