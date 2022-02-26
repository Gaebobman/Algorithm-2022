# https://www.acmicpc.net/problem/2751
# Sort
import sys

input = sys.stdin.readline
N = int(input())
data = []
for _ in range(N):
    data.append(int(input()))
data.sort()
for i in data:
    print(i)

