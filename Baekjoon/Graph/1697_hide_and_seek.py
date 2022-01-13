# https://www.acmicpc.net/problem/1697
# BFS
from collections import deque

N, K = map(int, input().split())
visited = [False] * 100001
visited[N] = True

queue = deque()  # 좌표 x와 ,Hop (x, hop)
queue.append((N, 0))
result = 0
while queue:
    x, time = queue.popleft()
    if x == K:
        result = time
        break
    tx = 0
    # -1
    if x - 1 >= 0 and visited[x - 1] == False:
        queue.append((x - 1, time + 1))
        visited[x - 1] = True
    # +1
    if x + 1 < 100001 and visited[x + 1] == False:
        queue.append((x + 1, time + 1))
        visited[x + 1] = True
    # X2
    if x * 2 < 100001 and visited[x * 2] == False:
        queue.append((x * 2, time + 1))
        visited[x * 2] = True

print(result)
