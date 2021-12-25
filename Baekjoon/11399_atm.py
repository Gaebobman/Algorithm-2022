# https://www.acmicpc.net/problem/11399
# Greedy
import sys

N = int(sys.stdin.readline().rstrip())
data = list(map(int, input().split()))
data.sort()

result = 0

for i in range(N):
    result += (N - i) * data[i]

print(result)
