# https://www.acmicpc.net/problem/1789
# Greedy

S = int(input())
sum = 0

for i in range(1, S + 1):
    sum += i
    if sum == S:
        print(i)
        break
    elif sum > S:
        print(i - 1)
        break
