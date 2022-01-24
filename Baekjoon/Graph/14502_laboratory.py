# https://www.acmicpc.net/problem/14502
# BFS + Brute force
import copy
import sys
from collections import deque

input = sys.stdin.readline
N, M = map(int, input().split())

# graph = [list(map(int, input().split())) for _ in range(N)]
graph =[[0]* N for _ in range(M)]

for i in range(N):
    for j in range(M):

safe_zone = []
virus = []
for i in range(N):
    for j in range(M):
        if graph[i][j] == 0:
            safe_zone.append((i, j))
        elif graph[i][j] == 2:
            virus.append((i, j))

# 상 하 좌 우
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]


# 0 == 빈칸 / 1 == 벽 / 2 == 바이러스
def bfs(g):
    q = deque()
    for v in virus:
        q.append(v)
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

    return safe_count


result = []

# 무작위로 3개의 칸막이를 설치하고 BFS 를 실행, 결과값을 모조리 저장
for i in range(len(safe_zone)):
    for j in range(1, len(safe_zone)):
        for k in range(2, len(safe_zone)):
            tmp_graph = copy.deepcopy(graph)
            x1, y1 = safe_zone[i]
            x2, y2 = safe_zone[j]
            x3, y3 = safe_zone[k]
            tmp_graph[x1][y1] = 1
            tmp_graph[x2][y2] = 1
            tmp_graph[x3][y3] = 1
            result.append(bfs(tmp_graph))


print(max(result))
