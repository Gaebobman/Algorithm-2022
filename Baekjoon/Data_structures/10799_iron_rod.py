# https://www.acmicpc.net/problem/10799
# Data structure
import sys

input = sys.stdin.readline
data = input().rstrip()
stack = []
total = 0
for i in range(len(data)):
    # ( 이면 스택에 넣고
    if data[i] == '(':
        stack.append('(')
    else:
        # 레이져의 경우
        if data[i - 1] == ('('):
            stack.pop()
            total += len(stack)
        # 쇠막대가 그냥 끝나는 경우
        else:
            stack.pop()
            total += 1
print(total)
