# https://www.acmicpc.net/problem/1158
# Data structure / Circular Linked List
N, K = map(int, input().split())
array = [i for i in range(1, N + 1)]
head = 0
res = []
for i in range(N):
    head = (head + (K - 1)) % len(array)
    res.append(str(array.pop(head)))
print("<%s>" %(", ".join(res)))
