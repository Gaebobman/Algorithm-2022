# https://www.acmicpc.net/problem/12015
# Binary search
import sys
from bisect import bisect_left

input = sys.stdin.readline
N = int(input())
data = list(map(int, input().split()))
result = [data[0]]

for num in data:
    if result[-1] < num:
        result.append(num)
    else:
        result[bisect_left(result, num)] = num

print(len(result))

