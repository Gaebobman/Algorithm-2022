# https://www.acmicpc.net/problem/2164
# Data structure
from collections import deque

N = int(input())
cards = deque(i for i in range(1, N + 1))
while len(cards) > 1:
    cards.popleft()
    cards.append(cards.popleft())
print(cards[0])