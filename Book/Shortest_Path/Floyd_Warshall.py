import sys

input = sys.stdin.readline

INF = (1e9)
n = int(input())
m = int(input())

graph = [[INF] * (n + 1) for _ in range(n + 1)]

# diagonal component == 0   -> 자기 자신에서부터 자기 자신까지의 거리
for i in range(n + 1):
    graph[i][i] = 0

for _ in range(m):
    # a에서 b로 가는 비용은 c 이다
    a, b, c = map(int, input().split())
    graph[a][b] = c

for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

for a in range(1, n + 1):
    for b in range(1, n + 1):
        if graph[a][b] == INF:
            print("-1")
        else:
            print(graph[a][b], end=' ')
    print()