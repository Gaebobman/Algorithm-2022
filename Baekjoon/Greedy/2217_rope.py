# https://www.acmicpc.net/problem/2217
# Greedy

N = int(input())
rope = []
result = []

for _ in range(N):
    rope.append(int(input()))
rope.sort(reverse=True)

for i in range(len(rope)):
    result.append(rope[i] * (i + 1))


print(max(result))
