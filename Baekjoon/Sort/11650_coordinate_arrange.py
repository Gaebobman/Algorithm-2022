# https://www.acmicpc.net/problem/11650
# Sort (Merge sort)
import sys


def merge_sort(arr):
    if len(arr) == 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)


def merge(left, right):
    sorted_arr = []
    while len(left) > 0 and len(right) > 0:
        if left[0] < right[0]:    # 왼쪽 x 좌표가 더 작으면 / y좌표 까지도 계산 된다
            sorted_arr.append(left.pop(0))
        else:
            sorted_arr.append(right.pop(0)) # 오른쪽 y 좌표가 크거나 같으면
    if len(left) > 0:
        sorted_arr += left
    if len(right) > 0:
        sorted_arr += right
    return sorted_arr


input = sys.stdin.readline
N = int(input())
data = []
for _ in range(N):
    x, y = map(int, input().split())
    data.append((x, y))
sorted_data = merge_sort(data)
for coordinate in sorted_data:
    print(coordinate[0], coordinate[1])