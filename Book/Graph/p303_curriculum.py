from collections import deque
from copy import deepcopy

N = int(input())
time = [0] * (N + 1)
in_degree = [0] * (N + 1)
graph = [[] for _ in range(N + 1)]

for i in range(1, N + 1):
    data = list(map(int, input().split()))
    time[i] = data[0]

    # idx 1 부터 뒤에서 1번째(idx -0부터 시작)까지
    for j in data[1:-1]:
        graph[j].append(i)
        in_degree[i] += 1

# Topology sort 시작
queue = deque()
result = deepcopy(time)
# in degree 0 인 Node 부터 시행 (여러개 존재 가능)
for i in range(1, N + 1):
    if in_degree[i] == 0:
        queue.append(i)

while queue:
    now = queue.popleft()

    for node in graph[now]:
        in_degree[node] -= 1
        result[node] = max(result[node], result[now] + time[node])
        if in_degree[node] == 0:
            queue.append(node)

for i in range(1, N + 1):
    print(result[i])
