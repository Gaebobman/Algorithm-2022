# DP
# 일단 coin 하나만 써서 만들 수 있는 수를 모두 만들어서 DP 테이블에 적는다
# coin[0] ~ coin[N -1] 로 가면서 단순 최적화 된다 (여기까지 채워진 수들은 가능한 최적화 한거임)
# 그 후 채워진 DP 테이블 (단일 종류로만 만들어진 테이블임)을 조합으로 만들 수 있는 테이블로 변화시키자 (이게 진짜 최적화임)

N, M = map(int, input().split())
coins = []  # 입력받을 동전 종류
D = [0] * (M + 1)  # DP Table

for i in range(N):
    x = int(input())
    coins.append(x)

for coin in coins:
    for i in range(M + 1):
        if i % coin == 0:
            D[i] = i // coin
        elif D[i] != 0 and (i + coin) <= (M):
            D[i + coin] = D[i] + 1

if D[M] == 0:
    print(-1)
else:
    print(D[M])