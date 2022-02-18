# https://www.acmicpc.net/problem/1010
# DP (인줄 알았는데 Combination 으로 빠르게 연산 가능)
from math import comb

for _ in range(int(input())):
    n, m = map(int, input().split())
    print(comb(m, n))


