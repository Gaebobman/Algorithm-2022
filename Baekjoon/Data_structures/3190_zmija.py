# https://www.acmicpc.net/problem/3190
# Data structure
# 게임의 종료 조건 => 벽에 박거나 자기 몸에 닿으면 끝
import sys
from collections import deque

input = sys.stdin.readline
N, K = int(input()), int(input())
board = [[0] * (N + 1) for _ in range(N + 1)]  # 게임 맵 (1-base)
for _ in range(K):
    x, y = map(int, input().split())
    board[x][y] = 1  # (0: 빈 맵, 1: 사과)
L = int(input())
move = []  # 움직임 정보를 담고 있음
for _ in range(L):
    X, C = input().split()
    move.append([int(X), C])
# 상, 우, 하, 좌 의 움직임 정보 (시계 방향)
dx = [-1, 0, 1, 0]
dy =[0, 1, 0, -1]
direction = 1  # 시작할 때 우측을 보고 시작
snake = deque()  # 뱀의 좌표를 가짐
snake.append((1, 1))
time, move_number = 0, 0  # 게임 시간과 움직임 번호
while True:
    time += 1
    # 머리가 이동할 다음 칸을 계산
    t_head_x = snake[0][0] + dx[direction]
    t_head_y = snake[0][1] + dy[direction]
    # 벽에 박아 죽었는지 확인
    if t_head_x <= 0 or t_head_x > N or t_head_y <= 0 or t_head_y > N:
        break
    # 몸에 닿아 죽었는지 확인
    if (t_head_x, t_head_y) in snake:
        break
    # 머리를 이동 시킴
    snake.appendleft((t_head_x, t_head_y))
    # 사과를 없으면 꼬리 자름
    if board[t_head_x][t_head_y] == 0:
        snake.pop()
    # 사과가 있으면 먹음
    else:
        board[t_head_x][t_head_y] = 0

    # 방향 전환을 할 시간 이라면 방향을 바꿔 준다
    if move_number < L:
        if time == move[move_number][0]:
            if move[move_number][1] == "L":
                direction = (direction + 3) % 4
                move_number += 1
            elif move[move_number][1] == "D":
                direction = (direction + 1) % 4
                move_number += 1

print(time)
