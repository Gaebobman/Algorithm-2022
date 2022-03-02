# https://www.acmicpc.net/problem/9012
# Data structures
import sys

input = sys.stdin.readline
N = int(input())

for _ in range(N):
    data = input().rstrip()
    res = 0
    for i in range(len(data)):
        if data[i] == '(':
            res += 1
        else:
            res -= 1
        if res == -1:
            break
    if res == 0:
        print("YES")
    else:
        print("NO")

