# https://www.acmicpc.net/problem/10816
# Binary search
import sys

input = sys.stdin.readline


def lower_bound(data, x):
    start = 0
    end = len(data)
    while start < end:
        mid = (start + end) // 2
        if data[mid] >= x:
            end = mid
        else:
            start = mid + 1
    return start


def upper_bound(data, x):
    start = 0
    end = len(data)
    while start < end:
        mid = (start + end) // 2
        if data[mid] > x:
            end = mid
        else:
            start = mid + 1
    return start


def binary_search(data, x):
    low = lower_bound(data, x)
    high = upper_bound(data, x)
    print(x, " 의 상한 :", high, " 하한: ", low)

    return 0 if low == -1 else upper_bound(data, x) - low + 1


N = int(input())
data = list(map(int, input().split()))
M = int(input())
target = list(map(int, input().split()))
data.sort()
result = []
for i in target:
    result.append(upper_bound(data, i)- lower_bound(data, i))
for i in result:
    print(i, end=' ')
