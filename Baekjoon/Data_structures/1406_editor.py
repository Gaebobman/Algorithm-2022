# https://www.acmicpc.net/problem/1406
# Data structure \ Stack
import sys

input = sys.stdin.readline
left_string = list((input().rstrip()))
right_string = []
N = int(input())
for i in range(N):
    command = input().strip().split()
    if command[0] == "L":
        if len(left_string):
            right_string.append(left_string.pop())
    elif command[0] == "D":
        if len(right_string):
            left_string.append(right_string.pop())
    elif command[0] == "B":
        if len(left_string):
            left_string.pop()
    elif command[0] == "P":
        left_string.append(command[1])

while(len(right_string)):
    left_string.append(right_string.pop())

print(''.join(left_string))


