# https://www.acmicpc.net/problem/17298
# Data structure
import sys

input = sys.stdin.readline
N = int(input())
data = list(map(int, input().split()))
stack = []
answer = []
for i in range(N - 1, -1, -1):
    if len(stack) == 0:
        answer.append(-1)
        stack.append(data[i])
        continue
    while len(stack) != 0 and stack[-1] <= data[i]:
        stack.pop()
    if len(stack) == 0:
        answer.append(-1)
        stack.append(data[i])
        continue
    answer.append(stack[-1])
    stack.append(data[i])
answer.reverse()
for x in answer:
    print(x, end=' ')