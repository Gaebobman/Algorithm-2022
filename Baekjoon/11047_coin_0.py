# https://www.acmicpc.net/problem/11047
# Greedy

N, K = list(map(int, input().split()))
coins = []
result = 0

# 동전 입력
for i in range(N):
    coins.append(int(input()))

# 가장 큰 동전부터 확인
current_coin_idx = N - 1

while current_coin_idx >= 0:
    if K < coins[current_coin_idx]:
        current_coin_idx -= 1
    else:
        result += K // coins[current_coin_idx]      # 동전 몇 개 추가?
        K %= coins[current_coin_idx]
        current_coin_idx -= 1

print(result)
