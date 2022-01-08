import sys

input = sys.stdin.readline  # input() 을 치환

INF = int(1e9)

n, m = map(int, input().split())  # 노드갯수 n / 간선갯수 m

start = int(input())

graph = [[] for i in range(n + 1)]
visited = [False] * (n + 1)
distance = [INF] * (n + 1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))


def get_smallest_node():
    min_val = INF
    idx = 0
    for i in range(1, n + 1):
        if distance[i] < min_val and not visited[i]:
            min_val = distance[i]
            idx = i
    return idx


def dijkstra(start):
    distance[start] = 0  # 시작점의 cost = 0
    visited[start] = True
    for j in graph[start]:
        distance[j[0]] = j[1]

    # 시작노드 제외한 노드에 대해 수행
    for i in range(n - 1):
        now = get_smallest_node()
        visited[now] = True
        for j in graph[now]:
            cost = distance[now] + j[1]
            if cost < distance[j[0]]:
                distance[j[0]] = cost


dijkstra(start)

for i in range(1, n + 1):
    if distance[i] == INF:
        print("INF")
    else:
        print(distance[i])
