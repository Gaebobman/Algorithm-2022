# https://www.acmicpc.net/problem/2110
# Binary search / Parametric search
# 간격 X 이상의 거리에 공유기를 설치함
# C 보다 크면 간격을 넓힌다
# C 보다 작으면 간격을 좁힌다
# 간격은 binary search 한다.
# 최대거리니깐 Upper Bound 서치하자

import sys

input = sys.stdin.readline


# 공유기 거리가 주어지면 몇 개 설치할 수 있는지 return 하는 함수
def plant(array, length):
    last_planted = 0   # 마지막 설치 위치
    planted_num = 1
    for i in range(1, len(array)):
        if array[i] - array[last_planted] >= length:
            planted_num += 1
            last_planted = i
    return planted_num


def binary_search(array, c):
    low = 1     # 최소거리
    high = array[-1] - array[0] + 1  # 최대거리
    while low < high:
        mid = (low + high) // 2
        if plant(array, mid) < c:
            high = mid
        else:
            low = mid + 1
    print(low - 1)


N, C = map(int, input().split())
data = []
for _ in range(N):
    x = int(input())
    data.append(x)
data.sort()
binary_search(data, C)
