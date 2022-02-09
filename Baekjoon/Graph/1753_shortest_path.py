# https://www.acmicpc.net/problem/1753
# Dijkstra
import heapq
import sys

INF = 1e9
input = sys.stdin.readline
V, E = map(int, input().split())
K = int(input())

distance = [INF] * (V + 1)
graph = [[] for _ in range(V + 1)]
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))


def dijkstra(start):
    q = []
    # heap 에 Cost, Vertex 순서대로 넣어야 최단시간을 보장함
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue

        for edge in graph[now]:
            cost = edge[1] + dist
            if cost < distance[edge[0]]:
                distance[edge[0]] = cost
                heapq.heappush(q, (cost, edge[0]))


dijkstra(K)

for i in range(1, V + 1):
    if distance[i] == INF:
        print("INF")
    else:
        print(distance[i])
