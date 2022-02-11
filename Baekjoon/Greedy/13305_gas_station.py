# https://www.acmicpc.net/problem/13305
# Greedy

N = int(input())
roads = list(map(int, input().split()))
cities = list(map(int, input().split()))
minimum = cities[0]
result = roads[0] * cities[0]

for i in range(1, N - 1):
    # 최솟값보다 크면
    if minimum <= cities[i]:
        result += minimum * roads[i]
    else:
        minimum = cities[i]
        result += minimum * roads[i]

print(result)
