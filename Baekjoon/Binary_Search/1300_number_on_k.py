# https://www.acmicpc.net/problem/1300
# Binary search
def binary_search(n, k):
    # 1 부터 N X N 까지의 범위
    # k 앞에 숫자 몇 개가 있는지 세보자
    low = 1
    high = n * n
    while low <= high:
        mid = (low + high) // 2
        index = 0
        for i in range(1, n + 1):
            index += min(mid // i, n)   # i는 행 번호임
        if index < k:
            low = mid + 1
        else:
            high = mid - 1
    print(low)


N = int(input())
K = int(input())
binary_search(N, K)
