# https://www.acmicpc.net/problem/2805
# Binary search
import sys

input = sys.stdin.readline


def chop_tree(data, x):
    res = 0
    for tree in data:
        if tree > x:
            res += tree - x
    return res


def binary_search(data, m):
    start = 0
    end = max(data)
    mid = 0
    while start <= end:
        mid = (start + end) // 2
        if chop_tree(data, mid) >= m:
            start = mid + 1
        else:
            end = mid - 1
    return end


N, M = map(int, input().split())
data = list(map(int, input().split()))
print(binary_search(data, M))
