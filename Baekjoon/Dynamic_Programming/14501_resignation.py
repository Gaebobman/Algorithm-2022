# https://www.acmicpc.net/problem/14501
# DP
# t == time, p == pay
N = int(input())
data = []
D = []
for _ in range(N):
    t, p = map(int, input().split())
    data.append((t, p))
    D.append(p)

for i in range(0, N):
    for j in range(i):
        # 기준일 이전일(j)에 시작한 작업이 기준일에 끝나면(작업 가능하면 비교)
        if data[j][0] <= i - j:
            D[i] = max(data[i][1] + D[j], D[i])
    # 또한 퇴사일 이전에 끝나는지 확인
    if data[i][0] + i > N:
        D[i] = 0
print(max(D))
