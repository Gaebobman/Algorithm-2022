# https://www.acmicpc.net/problem/1874
# Data structure
import sys
from collections import deque

input = sys.stdin.readline
N = int(input())
data, stack = deque(int(input()) for _ in range(N)), deque()
result = ['+']
stack.appendleft(1)
current_number = 2
while current_number <= N:
    if data[0] > stack[0]:
        stack.appendleft(current_number)
        current_number += 1
        result.append('+')
    elif data[0] == stack[0]:
        stack.popleft()
        data.popleft()
        result.append('-')
    else:
        result = "NO"
        break
    if len(stack) == 0:
        stack.appendleft(current_number)
        current_number += 1
        result.append('+')


if len(data) == len(stack):
    # 내용이 동일한지 비교
    for i in range(len(data)):
        if data.popleft() != stack.popleft():
            result = "NO"
            break
        else:
            result.append('-')
if result == "NO":
    print("NO")
else:
    for operator in result:
        print(operator)

