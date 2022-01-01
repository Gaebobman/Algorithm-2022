# Sort
import sys

N = int(sys.stdin.readline().rstrip())
data = []
for _ in range(N):
    student = input().split()
    data.append((student[0], int(student[1])))

data = sorted(data, key=lambda s: s[1])

for tup in data:
    print(tup[0], end=' ')
