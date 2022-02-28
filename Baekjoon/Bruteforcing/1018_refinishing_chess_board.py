# https://www.acmicpc.net/problem/1018
# Brute forcing
import sys

WHITE_START = ['WBWBWBWB',
               'BWBWBWBW',
               'WBWBWBWB',
               'BWBWBWBW',
               'WBWBWBWB',
               'BWBWBWBW',
               'WBWBWBWB',
               'BWBWBWBW']
BLACK_START = ['BWBWBWBW',
               'WBWBWBWB',
               'BWBWBWBW',
               'WBWBWBWB',
               'BWBWBWBW',
               'WBWBWBWB',
               'BWBWBWBW',
               'WBWBWBWB']
input = sys.stdin.readline
N, M = map(int, input().split())
board = [input().rstrip() for _ in range(N)]  # 입력 받은 체스판
minimum = 1e9   # 최소 변경 값

for i in range(N - 7):
    for j in range(M - 7):
        changed_white = 0   # 하얀색 으로 시작 해서 바뀐 수
        changed_black = 0
        for a in range(8):
            for b in range(8):
                if WHITE_START[a][b] != board[a + i][b + j]:
                    changed_white += 1
                if BLACK_START[a][b] != board[a + i][b + j]:
                    changed_black += 1
        minimum = min(minimum, changed_white, changed_black)

print(minimum)