# Sort
import sys

N = int(sys.stdin.readline().rstrip())
arr = []
for _ in range(N):
    x = int(input())
    arr.append(x)

arr.sort(reverse=True)

for i in range(N):
    print(arr[i], end=' ')
