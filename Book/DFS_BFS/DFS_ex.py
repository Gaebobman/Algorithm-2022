def dfs(graph, v, visited):
    visited[v] = 1
    print(v)
    for vertex in graph[v]:
        if visited[vertex] == 0:
            dfs(graph, vertex, visited)

graph = [
    [],
    [2, 3, 8],
    [1, 7],
    [1, 4, 5],
    [3, 5],
    [3, 4],
    [7],
    [2, 6, 8],
    [1, 7]
]

visited = [0] * 9

dfs(graph, 1, visited)
