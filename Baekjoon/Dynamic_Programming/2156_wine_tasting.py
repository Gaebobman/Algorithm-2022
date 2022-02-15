# https://www.acmicpc.net/problem/2156
# DP
N = int(input())
D = [0 for _ in range(N)]
data = []
for _ in range(N):
    x = int(input())
    data.append(x)
if N < 3:
    print(sum(data))
else:
    D[0] = data[0]
    D[1] = data[0] + data[1]
    D[2] = max(data[0] + data[1], data[1] + data[2], data[0] + data[2])
    for i in range(3, N):
        D[i] = max(D[i - 1], D[i - 3] + data[i - 1] + data[i], D[i - 2] + data[i])
        # i 안먹기, i - 1 이랑 i 먹기, 연속 두 번 안 먹고 i 먹기
    print(D[N - 1])
