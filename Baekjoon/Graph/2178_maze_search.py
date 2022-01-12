# https://www.acmicpc.net/problem/2178
# BFS
import sys
from collections import deque

input = sys.stdin.readline
N, M = map(int, input().split())

maze = []
for _ in range(N):
    maze.append(list(map(int, input().rstrip())))

# 상하좌우
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

queue = deque()
queue.append((0, 0))

while queue:
    # 현 좌표
    x, y = queue.popleft()
    # dx, dy 활용하여 상하좌우 확인
    for i in range(4):
        tx = x + dx[i]
        ty = y + dy[i]
        # 이동불가시 Continue
        if (0 > tx or tx >= N) or (0 > ty or ty >= M) or maze[tx][ty] != 1:
            continue
        # 이동 가능시 큐에 삽입, Cost 증가
        else:
            queue.append((tx, ty))
            maze[tx][ty] += maze[x][y]

print(maze[N - 1][M - 1])
