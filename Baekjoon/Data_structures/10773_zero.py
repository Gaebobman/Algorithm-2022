# https://www.acmicpc.net/problem/10773
# Data structure
import sys

input = sys.stdin.readline
K = int(input())
data = []
for _ in range(K):
    x = int(input())
    if x == 0 and len(data) != 0:
        data.pop(-1)
    else:
        data.append(x)
print(sum(data))
