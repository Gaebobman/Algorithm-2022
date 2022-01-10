def find_parent(parent, x):
    # Root Node 가 아니라면
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])  # 재귀적으로 호출 / 경로압축(Path compression)사용
    return parent[x]


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    # 작은 parent idx 우선
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


v, e = map(int, input().split())
parent = [0] * (v + 1)  # 부모 테이블 초기화

for i in range(v + 1):
    parent[i] = i

for i in range(e):
    a, b = map(int, input().split())
    union_parent(parent, a, b)

print('각 원소가 속한 집합: ', end=' ')
for i in range(1, v + 1):
    print(find_parent(parent, i), end=' ')

print("\n부모테이블: ", end='')
for i in range(1, v + 1):
    print(parent[i], end=' ')
