# https://www.acmicpc.net/problem/1764
# Sort
import sys

input = sys.stdin.readline
N, M = map(int, input().split())
unheard = set()
unseen = set()

for _ in range(N):
    unheard.add(input().rstrip())
for _ in range(M):
    unseen.add(input().rstrip())
unknown = sorted(list(unheard.intersection(unseen)))
print(len(unknown))
for person in unknown:
    print(person)