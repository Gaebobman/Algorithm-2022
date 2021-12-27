# https://www.acmicpc.net/problem/1026
# Greedy
import math
import sys

# N, A, B 입력
import time

N = int(sys.stdin.readline().rstrip())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
# 출력할 결과 값
result = 0

A.sort()

# Trivial and not acceptable (B는 건들지 말라했음)
# B.sort(reverse=True)
#
# for i in range(N):
#     result += A[i] * B[i]

for i in range(N):
    result += A[i] * B.pop(B.index(max(B)))

print(result)

