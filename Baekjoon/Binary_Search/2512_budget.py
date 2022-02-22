# https://www.acmicpc.net/problem/2512
# Binary search
# Upper Bound 를 찾는 문제인 듯?
import sys


# 예산을 계산하는 함수
def get_budget(array, n, maximum):
    result = 0
    for i in range(n):
        if array[i] > maximum:
            result += (n - i) * maximum
            break
        result += array[i]
    return result


def binary_search(array, n, m):
    low = 0
    high = array[-1]
    while low <= high:
        mid = (low + high) // 2
        if get_budget(array, n, mid) <= m:
            low = mid + 1
        else:
            high = mid - 1
    print(high)


input = sys.stdin.readline
N = int(input())
data = list(map(int, input().split()))
data.sort()
M = int(input())
if sum(data) < M:
    print(data[-1])
else:
    binary_search(data, N, M)
