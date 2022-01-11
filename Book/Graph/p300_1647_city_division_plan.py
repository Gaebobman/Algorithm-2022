# https://www.acmicpc.net/problem/1647
# Spanning Tree (Using Kruskal algorithm)
import sys


def find_parent(parent: list, x: int):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union_parent(parent: list, a: int, b: int):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


input = sys.stdin.readline  # 빠른 입력을 위함

N, M = map(int, input().split())
result = 0  # 최소 비용 신장트리의 Cost - 가장 비싼 cost
edges = []  # 길의 정보
parent = [i for i in range(N + 1)]  # Parent Node 를 담는 리스트, 초기 자기자신이 parent

for _ in range(M):
    a, b, cost = map(int, input().split())
    edges.append((cost, a, b))  # Cost 기준 정렬을 위함

edges.sort()

# 마을을 두개로 나눌 때 가장 Cost 가 큰 길 하나만 삭제하면 된다
# 현재 길이 cost 순으로 나열되어 있으므로 마지막 edge 만 지우면 마을이 두 개로 분할 됨

for i in range(len(edges)):
    # print("현 EDGE", edges[i])
    cost, a, b = edges[i]

    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        # print(a, b ,"연결함")
        result += cost
        last = cost

print(result - last)
