# DFS/BFS
from collections import deque

N, M = map(int, input().split())

maze = []

for _ in range(N):
    maze.append(list(map(int, input())))


cost = 1
# 상 하 좌 우
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]


queue = deque()
queue.append((0, 0))

while queue:

    x, y = queue.popleft()
    cost = maze[x][y]
    print(f"현 위치: [{x, y}]")
    # 4방향 확인 하기
    for i in range(4):
        tx = x
        ty = y
        tx += dx[i]
        ty += dy[i]
        # 범위를 벗어나는 경우에는
        if tx < 0 or ty < 0 or tx >= N or ty >= M:
            continue
        # 미로 벽인 경우에는
        if maze[tx][ty] == 0:
            continue
        # 첫 방문 시에는, Cost 증가.
        if maze[tx][ty] == 1:
            queue.append((tx, ty))
            maze[tx][ty] += cost


print(maze[N - 1][M -1])

