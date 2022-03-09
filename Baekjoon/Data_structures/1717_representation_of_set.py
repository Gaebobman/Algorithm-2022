# https://www.acmicpc.net/problem/1717
# Data structure / Disjoint set
import sys


def find_parent(parent, x):
    while True:
        if parent[x] == x:
            break
        parent[x] = parent[parent[x]]
        x = parent[x]
    return parent[x]


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


input = sys.stdin.readline
N, M = map(int, input().split())
parent = [i for i in range(N + 1)]

for _ in range(M):
    k, a, b = map(int, input().split())
    if k == 0:
        union_parent(parent, a, b)
    else:
        if find_parent(parent, a) == find_parent(parent, b):
            print('YES')
        else:
            print('NO')
