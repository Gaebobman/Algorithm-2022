# https://www.acmicpc.net/problem/1920
# Binary search
import sys

input = sys.stdin.readline


def binary_search(arr: list, x: int):
    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == x:
            return 1
        if arr[mid] < x:
            start = mid + 1
        else:
            end = mid - 1
    return 0


N = int(input())
data = list(map(int, input().split()))
data.sort()
M = int(input())
num = list(map(int, input().split()))
for i in range(M):
    print(binary_search(data, num[i]))
