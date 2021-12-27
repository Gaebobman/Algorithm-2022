# https://www.acmicpc.net/problem/1260
# DFS_BFS
from collections import deque


def dfs(matrix, v, visited):
    visited[v] = True
    print(v, end=' ')

    for vertex in range(len(matrix[v])):
        if not visited[vertex] and matrix[v][vertex] == 1:
            dfs(matrix, vertex, visited)


def bfs(matrix, v, visited):
    queue = deque([v])
    visited[v] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for vertex in range(len(matrix[v])):
            if not visited[vertex] and matrix[v][vertex] == 1:
                queue.append(vertex)
                visited[vertex] = True


N, M, V = map(int, input().split())

# 인접행렬
matrix = [[0] * (N + 1) for _ in range(N + 1)]

for _ in range(M):
    row, column = map(int, input().split())
    matrix[row][column] = 1
    matrix[column][row] = 1

visited = [False] * (N + 1)
visited[0] = True
dfs(matrix, V, visited)
visited = [False] * (N + 1)
visited[0] = True
print()
bfs(matrix, V, visited)

