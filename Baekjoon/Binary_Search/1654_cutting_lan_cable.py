# https://www.acmicpc.net/problem/1654
# Binary search
import sys
input = sys.stdin.readline


def cut_lan_cable(cables, length):
    result = 0
    for cable in cables:
        result += cable // length
    return result


def binary_search(cables, n):
    start, end = 0, max(cables)
    while start <= end:
        mid = (start + end) // 2
        if mid == 0:
            break
        cable_num = cut_lan_cable(cables, mid)
        if cable_num >= n:
            start = mid + 1
        else:
            end = mid - 1
    return end


K, N = map(int, input().split())
lan_cable = []
for _ in range(K):
    x = int(input())
    lan_cable.append(x)
print(binary_search(lan_cable, N))
