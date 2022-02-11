# https://www.acmicpc.net/problem/1946
# Greedy
import sys
from collections import deque

input = sys.stdin.readline
T = int(input())

for _ in range(T):
    result = 1
    recruits = []
    N = int(input())
    for _ in range(N):
        a, b = map(int, input().split())
        recruits.append((a, b))
    recruits.sort()
    min_b = recruits[0][1]

    for i in recruits:
        if i[1] < min_b:
            result += 1
            min_b = i[1]
    print(result)
