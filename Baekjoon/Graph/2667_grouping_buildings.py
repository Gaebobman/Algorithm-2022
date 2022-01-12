# https://www.acmicpc.net/problem/2667
# DFS
import sys

input = sys.stdin.readline
N = int(input())

data = []

for _ in range(N):
    data.append(list(map(int, input().rstrip())))

# 상하좌우
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]


def dfs(data, x, y):
    building_count = 1
    stack = []
    stack.append((x, y))
    data[x][y] = 0

    while stack:
        x, y = stack.pop()
        for i in range(4):
            tx = x + dx[i]
            ty = y + dy[i]
            # 빌딩이 아니면 continue
            if (0 > tx or tx >= N) or (0 > ty or ty >= N) or data[tx][ty] != 1:
                continue
            else:
                data[tx][ty] = 0
                stack.append((tx, ty))
                building_count += 1

    if building_count != 0:
        return building_count


result = []
for i in range(N):
    for j in range(N):
        if data[i][j] != 0:
            result.append(dfs(data, i, j))

print(len(result))
result.sort()
for i in result:
    print(i)
