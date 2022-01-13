# https://www.acmicpc.net/problem/7576
# BFS
import sys
from collections import deque

input = sys.stdin.readline
M, N = map(int, input().split())
box = []
queue = deque()

for _ in range(N):
    box.append(list(map(int, input().split())))

# 1의 값을 가지는 idx 찾기/ 동시에 모두 1인지(-1과 1로만 이뤄졌는지) 확인)
fully_ripe_flag = True
for i in range(N):
    for j in range(M):
        if box[i][j] == 1:
            queue.append((i, j))
        if box[i][j] == 0:
            fully_ripe_flag = False

# 상하좌우
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
while queue and not fully_ripe_flag:
    x, y = queue.popleft()
    for i in range(4):
        tx = x + dx[i]
        ty = y + dy[i]

        if (0 > tx or tx >= N) or (0 > ty or ty >= M) or box[tx][ty] == -1:
            continue
        elif box[tx][ty] == 0:
            box[tx][ty] += box[x][y] + 1
            queue.append((tx, ty))


def check_box():
    maximum = 0
    for i in range(N):
        for j in range(M):
            if box[i][j] == 0:
                return -1
            else:
                maximum = max(maximum, box[i][j])
    return maximum - 1


check_value = check_box()
if check_value == -1 :
    print(-1)
elif fully_ripe_flag:
    print(0)
else:
    print(check_value)

