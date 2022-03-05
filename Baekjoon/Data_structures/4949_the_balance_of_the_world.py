# https://www.acmicpc.net/problem/4949
# Data structure

# 1. 문장의 끝은 '.' 이다
# 2. ( ), [ ] 제외 모두 버려 버린다
import sys

input = sys.stdin.readline
while True:
    stream = input().rstrip()
    # 입력 종료 조건
    if stream == ".":
        break
    stack = []
    # stream 을 보며 (, [ 만 Stack 에 넣고 빼고 한다
    # 짝이 맞는지 본다, 짝이 맞으면 yes 아니면 no를 출력
    for i in range(len(stream)):
        if stream[i] == '(' or stream[i] == '[':
            stack.append(stream[i])
        elif stream[i] == ')':
            if len(stack) == 0:
                stack.append(')')
                break
            elif stack[-1] == '(':
                stack.pop(-1)
            else:
                stack.append(')')
                break
        elif stream[i] == ']':
            if len(stack) == 0:
                stack.append(']')
                break
            elif stack[-1] == '[':
                stack.pop(-1)
            else:
                stack.append(']')
                break
    if len(stack) == 0:
        print("yes")
    else:
        print("no")
