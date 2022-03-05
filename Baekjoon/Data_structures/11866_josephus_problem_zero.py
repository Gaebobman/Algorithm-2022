# https://www.acmicpc.net/problem/11866
# Data structure

N, K = map(int, input().split())
sequence = [i for i in range(1, N + 1)]
result = []
head = 0
for _ in range(N):
    head = (head + K - 1) % len(sequence)
    result.append(str(sequence.pop(head)))
print("<%s>" % (", ".join(result)))
