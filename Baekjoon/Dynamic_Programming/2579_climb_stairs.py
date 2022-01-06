# https://www.acmicpc.net/problem/2579
# DP
import sys

N = int(input())  # 계단의 갯수
data = []

for _ in range(N):
    x = int(sys.stdin.readline().rstrip())
    data.append(x)

if N == 1:
    print(data[0])

elif N == 2:
    print(data[0] + data[1])

if N > 2:
    D = [[0]] * 300  # DP Table
    D[0] = data[0]  # 첫번째, 두번째 계단을 설정
    D[1] = data[0] + data[1]
    D[2] = max(data[0] + data[2], data[1] + data[2])

    for i in range(3, N):
        D[i] = max(data[i - 1] + D[i - 3], D[i - 2]) + data[i]

    print(D[N - 1])
