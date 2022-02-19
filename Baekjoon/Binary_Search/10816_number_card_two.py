# https://www.acmicpc.net/problem/10816
# Binary search
import sys

input = sys.stdin.readline


def binary_search(data, x, start_, end_):
    start = start_
    end = end_
    # 재귀적으로 불러 보자
    # 내가 타겟으로 삼은 인덱스가 안 나올때 까지 이분탐색을 돌리자



N = int(input())
data = list(map(int, input().split))
d = {}
for i in range(N):
    if data[i] not in d.keys():

    else:
M = int(input())
target = list(map(int, input().split()))


for i in target:
    pass