# https://www.acmicpc.net/problem/9461
# DP
D = [0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9]
for i in range(11, 101):
    D.append(D[i - 1] + D[i - 5])

T = int(input())
for _ in range(T):
    x = int(input())
    print(D[x])
