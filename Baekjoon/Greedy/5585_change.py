# https://www.acmicpc.net/problem/5585
# Greedy

N = 1000 - int(input())
CURRENCY = [500, 100, 50, 10, 5, 1]

result = 0

for currency in CURRENCY:
    if N < currency:
        continue
    else:
        result += N // currency
        N %= currency

print(result)
