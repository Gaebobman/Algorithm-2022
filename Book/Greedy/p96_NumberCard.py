n, m = map(int, input().split())

res = 0

for i in range(n):
    data = list(map(int, input().split()))
    minimum = min(data)
    if res < minimum:
        res = minimum

print(res)

