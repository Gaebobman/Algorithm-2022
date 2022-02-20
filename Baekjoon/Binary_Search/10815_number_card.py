# https://www.acmicpc.net/problem/10815
# Binary search
import sys

input = sys.stdin.readline


def binary_search(array, x):
    start = 0
    end = len(array) - 1
    while start <= end:
        mid = (start + end) // 2
        if array[mid] < x:
            start = mid + 1
        elif array[mid] > x:
            end = mid - 1
        else:
            break

    return 1 if array[mid] == x else 0


N = int(input())
data = list(map(int, input().split()))
M = int(input())
target = list(map(int, input().split()))
data.sort()
for i in target:
    print(binary_search(data, i))
