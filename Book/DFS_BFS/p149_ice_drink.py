# DFS/BFS

def check_ice_maker(x, y):
    global N
    global M
    if x < 0 or x >= N or y < 0 or y >= M:
        return -1
    if graph[x][y] == 0:
        graph[x][y] = 1
        check_ice_maker(x, y - 1)
        check_ice_maker(x, y + 1)
        check_ice_maker(x - 1, y)
        check_ice_maker(x + 1, y)
        return 1
    return -1


N, M = map(int, input().split())
graph = []
result = 0

# 얼음틀 입력
for _ in range(N):
    graph.append(list(map(int, input())))

for i in range(N):
    for j in range(M):
        if check_ice_maker(i, j) == 1:
            result += 1

print(result)