# https://www.acmicpc.net/problem/2606
# Disjoint Set

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


v = int(input())
e = int(input())
parent = [i for i in range(v + 1)]
graph = [[] for _ in range(v + 1)]
result = 0

for i in range(1, e + 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    union_parent(parent, a, b)


# print(parent)
for i in range(2, v + 1):
    if find_parent(parent, i) == 1:
        result += 1


print(result)
