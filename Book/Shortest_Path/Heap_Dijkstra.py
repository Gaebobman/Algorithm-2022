import heapq

INF = 987654321  # INF 를 매우 큰 수로 지정함

graph = [
    [],
    [(3, 1), (2, 3), (4, 4)],
    [(5, 4), (4, 6)],
    [(5, 7)],
    [(6, 4)],
    [(6, 3), (3, 7)],
    []
]
distance = [INF] * (6 + 1)  # 6개의 노드가 있는 리스트의 초기화


def dijkstra(start):
    queue = []
    heapq.heappush(queue, (0, start))
    distance[start] = 0

    while queue:
        dist, now = heapq.heappop(queue)
        if distance[now] < dist:
            continue

        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(queue, (cost, i[0]))


start_node = 1
dijkstra(start_node)

print("Node | ", end='')

for i in range(1, 6 + 1):
    print(i, end=' ')

print("\nCost | ", end='')

for i in range(1, 6 + 1):
    if distance[i] == INF:
        print("도달 불가능한 노드")
    else:
        print(distance[i], end=' ')
