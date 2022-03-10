# https://www.acmicpc.net/problem/18258
# Data structure
import sys
from collections import deque

input = sys.stdin.readline
q = deque()
for _ in range(int(input())):
    command = list(map(str, input().split()))
    if command[0] == "push":
        q.append(command[1])
    elif command[0] == "pop":
        if len(q) == 0:
            print(-1)
        else:
            print(q.popleft())
    elif command[0] == "size":
        print(len(q))
    elif command[0] == "empty":
        if len(q) == 0:
            print(1)
        else:
            print(0)
    elif command[0] == "front":
        if len(q) == 0:
            print(-1)
        else:
            print(q[0])
    elif command[0] == "back":
        if len(q) == 0:
            print(-1)
        else:
            print(q[-1])
