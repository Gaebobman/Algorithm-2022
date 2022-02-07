# https://www.acmicpc.net/problem/14502
# BFS + Brute force

import copy
import sys
from collections import deque

input = sys.stdin.readline
N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

global result
result = 0

# 상 하 좌 우
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]


# 0 == 빈칸 / 1 == 벽 / 2 == 바이러스
def bfs():
    global result
    q = deque()
    g = copy.deepcopy(graph)

    for i in range(N):
        for j in range(M):
            if g[i][j] == 2:
                q.append((i, j))

    while q:
        x, y = q.popleft()
        for i in range(4):
            tx = x + dx[i]
            ty = y + dy[i]
            if -1 < tx < N and -1 < ty < M and g[tx][ty] == 0:
                g[tx][ty] = 2
                q.append((tx, ty))

    safe_count = 0
    for i in range(N):
        safe_count += g[i].count(0)
    result = max(result, safe_count)


def wall(count):
    if count == 3:
        bfs()
        return

    for i in range(N):
        for j in range(M):
            if graph[i][j] == 0:
                graph[i][j] = 1
                wall(count + 1)
                graph[i][j] = 0


wall(0)
print(result)
