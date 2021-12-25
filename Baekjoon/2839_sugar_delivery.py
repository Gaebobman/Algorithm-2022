# https://www.acmicpc.net/problem/2839 설탕배달
# Greedy

# 봉지는 3KG, 5KG가 있다

N = int(input())
# 또는 빠른 입력 import sys 하고
# N = sys.stdin.readline().rstrip()


result = 0
while N >= 0:
    if N % 5 == 0:
        result += (N // 5)
        print(result)
        break
    N -= 3
    result += 1
else :
    print(-1)
