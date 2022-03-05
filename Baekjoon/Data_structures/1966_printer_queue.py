# https://www.acmicpc.net/problem/1966
# Data structure
import sys

input = sys.stdin.readline
T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    data = list(map(int, input().split()))
    data_idx = [i for i in range(N)]
    data_idx[M] = 'M'
    count = 0
    while count < N:
        if max(data) == data[0]:
            count += 1
            if data_idx[0] == 'M':
                print(count)
                break
            data.pop(0)
            data_idx.pop(0)
        else:
            data.append(data.pop(0))
            data_idx.append(data_idx.pop(0))
