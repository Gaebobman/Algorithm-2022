# https://www.acmicpc.net/problem/1181
# Sort
import sys

input = sys.stdin.readline
N = int(input())
data = []
for i in range(N):
    data.append(input().rstrip())
data = set(data)
data = list(data)
data.sort()
data = sorted(list(data), key=len)
for word in data:
    print(word)
