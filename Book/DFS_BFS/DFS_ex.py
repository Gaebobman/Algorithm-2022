def dfs(graph, v, visited):
    visited[v] = 1
    print(v, end= ' ')
    for vertex in graph[v]:
        if visited[vertex] == 0:
            dfs(graph, vertex, visited)

# graph = [
#     [],
#     [2, 3, 8],
#     [1, 7],
#     [1, 4, 5],
#     [3, 5],
#     [3, 4],
#     [7],
#     [2, 6, 8],
#     [1, 7]
# ]

graph = [
    [],
    [2, 5, 9],
    [1, 3],
    [2, 4],
    [3],
    [1, 6, 8],
    [5, 7],
    [6],
    [5],
    [1, 10],
    [9]
]

visited = [0] * 11

dfs(graph, 1, visited)
