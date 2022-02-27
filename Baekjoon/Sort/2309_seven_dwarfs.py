# https://www.acmicpc.net/problem/2309
# Sort
import sys

input = sys.stdin.readline
data = []
for _ in range(9):
    data.append(int(input()))
data.sort()
diff = sum(data) - 100

for i in range(9):
    for j in range(i, 9):
        if data[i] + data[j] == diff:
            data.remove(data[i])
            data.remove(data[j - 1])
            break
    if len(data) == 7:
        break
for i in range(7):
    print(data[i])