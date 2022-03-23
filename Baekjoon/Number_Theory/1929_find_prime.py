# https://www.acmicpc.net/problem/1929
#
M, N = map(int, input().split())
sieve = [i for i in range(0, N + 1)]
sieve[1] = 0
for i in range(2, N + 1):
    if sieve[i] == 0:
        continue
    j = i * 2
    while j <= N:
        sieve[j] = 0
        j += i
for i in range(M, N + 1):
    if sieve[i] != 0:
        print(sieve[i])