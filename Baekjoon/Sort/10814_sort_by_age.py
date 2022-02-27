# https://www.acmicpc.net/problem/10814
# Sort
import sys

input = sys.stdin.readline
N = int(input())
data = []
for _ in range(N):
    age, name = input().split()
    data.append((int(age), name.rstrip()))
data.sort(key=lambda item: item[0])
for i in range(N):
    print(data[i][0], data[i][1])
