# https://www.acmicpc.net/problem/3190
# Data structure
import sys

input = sys.stdin.readline
N, K = int(input()), int(input())
board = [[0] * (N + 1) for _ in range(N + 1)]
for _ in range(K):
    x, y = map(int, input().split())
    board[x][y] = 1
print(board)
L = int(input())
# for _ in range(L):
