# https://www.acmicpc.net/problem/10828
# Data structures

import sys


class Stack:
    def __init__(self):
        self.top = []

    def push(self, value):
        self.top.append(value)
        # print(self.top[-1])

    def pop(self):
        if self.empty() == 1:
            return -1
        else:
            return self.top.pop(-1)

    def size(self):
        return len(self.top)

    def empty(self):
        if len(self.top) == 0:
            return 1
        else:
            return 0

    def top_(self):
        if self.empty() == 1:
            return -1
        else:
            return self.top[-1]


input = sys.stdin.readline
N = int(input())
stack = Stack()
for _ in range(N):
    command = list(map(str, input().split()))
    if command[0] =="push":
        stack.push(int(command[1]))
    elif command[0] == "pop":
        print(stack.pop())
    elif command[0] == "size":
        print(stack.size())
    elif command[0] == "empty":
        print(stack.empty())
    elif command[0] == "top":
        print(stack.top_())
