# https://www.acmicpc.net/problem/1012
# DFS

import sys

T = int(input())


def dfs(field, M, N, x, y):
    # 상하좌우
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]
    stack = []
    stack.append((x, y))
    while stack:
        x, y = stack.pop()
        field[y][x] = 0
        for i in range(4):
            tx = x + dx[i]
            ty = y + dy[i]
            if tx <= -1 or tx >= M or ty <= -1 or ty >= N or field[ty][tx] == 0:
                continue
            else:
                field[ty][tx] = 0
                stack.append((tx, ty))


def print_field(field, M, N):
    for y in range(N):
        for x in range(M):
            print(field[y][x],end='')
        print()

def interface():
    M, N, K = map(int, input().split())
    field = [[0] * M for _ in range(N)]
    result = 0
    for _ in range(K):
        x, y = map(int, input().split())
        field[y][x] = 1
    for y in range(N):
        for x in range(M):
            if field[y][x] == 1:
                result += 1
                dfs(field, M, N, x, y)

    return result

res = []
for _ in range(T):
    res.append(interface())

for data in res:
    print(data, end='\n')
