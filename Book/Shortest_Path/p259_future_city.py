# Floyd Warshall algorithm

# 1 - 2
# |\ /
# 3-4
# |/
# 5

import sys


INF = (1e9)
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[INF] * (N + 1) for _ in range(N + 1)]

for i in range(N + 1):
    graph[i][i] = 0

for _ in range(M):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1

X, K = map(int, input().split())


for k in range(1, N + 1):
    for a in range(1, N + 1):
        for b in range(1, N + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])


result = graph[1][K] + graph[K][X]
if result >= INF:
    print(-1)
else:
    print(result)