# https://www.acmicpc.net/problem/11286
# Data structure
import heapq
import sys

input = sys.stdin.readline
data = []
for _ in range(int(input())):
    x = int(input())
    if x == 0:
        if len(data) == 0:
            print(0)
        else:
            print(heapq.heappop(data)[1])
    else:
        heapq.heappush(data, (abs(x), x))

