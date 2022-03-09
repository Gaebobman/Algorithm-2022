# https://www.acmicpc.net/problem/5430
# Data structure
import sys
from collections import deque

input = sys.stdin.readline
T = int(input())
for _ in range(T):
    P = list(map(str, input().rstrip()))
    P = deque(P)
    N = int(input())
    if N == 0:
        input()
        arr = deque()
    else:
        arr = deque(input().rstrip()[1:-1].split(','))
    r_count = 0
    error_flag = True
    loop = len(P)
    for _ in range(loop):
        if P[0] == 'R':
            P.popleft()
            r_count += 1
        elif P[0] == 'D':
            P.popleft()
            if len(arr) == 0:
                print("error")
                error_flag = False
                break
            if r_count % 2 == 1:
                arr.pop()
            else:
                arr.popleft()
    if error_flag:
        if r_count % 2 == 1:
            arr.reverse()
        print("[" + ",".join(arr) + "]")
