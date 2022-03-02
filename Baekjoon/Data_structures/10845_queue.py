# https://www.acmicpc.net/problem/10845
# Data structures
import sys
from collections import deque


class Queue:
    def __init__(self):
        self.entry = deque()

    def push(self, x):
        self.entry.append(x)

    def pop(self):
        if self.empty() == 1:
            return -1
        else:
            return self.entry.popleft()

    def size(self):
        return len(self.entry)

    def empty(self):
        if len(self.entry) == 0:
            return 1
        else:
            return 0

    def front(self):
        if self.empty() == 1:
            return -1
        else:
            return self.entry[0]

    def back(self):
        if self.empty() == 1:
            return -1
        else:
            return self.entry[-1]


input = sys.stdin.readline
N = int(input())
q = Queue()
for _ in range(N):
    command = list(map(str, input().split()))
    if command[0] == "push":
        q.push(int(command[1]))
    elif command[0] == "pop":
        print(q.pop())
    elif command[0] == "size":
        print(q.size())
    elif command[0] == "empty":
        print(q.empty())
    elif command[0] == "front":
        print(q.front())
    elif command[0] == "back":
        print(q.back())
