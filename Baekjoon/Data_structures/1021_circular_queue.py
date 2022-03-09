# https://www.acmicpc.net/problem/1021
# Data structure
# 1번연산 popleft
# 2번연산 popleft 한 것을 append
# 3번 연산 pop 한것을 appendleft
from sys import stdin
from collections import deque

input = stdin.readline
N, M = map(int, input().split())
target = deque(list(map(int, input().split())))
q = deque([i for i in range(1, N + 1)])
move = 0  # 2, 3 번 연산의 수
while len(target):
    x = target.popleft()
    # 좌 우 계산법
    # 현 리스트의 중간 인덱스를 기준으로 잡는다 == 5
    # 중간보다 작거나 같으면 우로 돌리기(Popleft and append
    # 중간보다 크면 좌로 돌린다(pop and appendleft)
    if q[0] == x:
        q.popleft()
    else:
        if q.index(x) <= len(q) // 2:
            while q[0] != x:
                q.append(q.popleft())
                move += 1
            q.popleft()
        else:
            while q[0] != x:
                q.appendleft(q.pop())
                move += 1
            q.popleft()
print(move)
