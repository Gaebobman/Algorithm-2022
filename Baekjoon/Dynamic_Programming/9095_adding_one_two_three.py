# https://www.acmicpc.net/problem/9095
# DP

T = int(input())
data = []
for _ in range(T):
    x = int(input())
    data.append(x)

D = [0] * 11
D[1] = 1
D[2] = 2
D[3] = 4

for i in range(4, 11):
    D[i] = D[i - 1] + D[i - 2] + D[i - 3]

for i in data:
    print(D[i])
