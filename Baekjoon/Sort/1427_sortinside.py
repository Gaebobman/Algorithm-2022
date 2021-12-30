# https://www.acmicpc.net/problem/1427
# Sort

# 0~9 이므로 계수정렬을 이용하자

def count_sort(arr):

    count = [0] * 10

    for i in range(len(arr)):
        count[arr[i]] += 1

    for i in range(9, -1, -1):
        for j in range(count[i]):
            print(i, end='')


N = list(map(int, input()))

count_sort(N)