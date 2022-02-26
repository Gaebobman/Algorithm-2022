# https://www.acmicpc.net/problem/10989
# Sort (Counting sort)
import sys

input = sys.stdin.readline
N = int(input())
data = [0] * 10001

for _ in range(N):
    data[int(input())] += 1
for i in range(10001):
    if data[i] != 0:
        for _ in range(data[i]):
            print(i)

