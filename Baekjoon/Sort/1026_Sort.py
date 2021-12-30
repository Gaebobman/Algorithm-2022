# https://www.acmicpc.net/problem/2750
# Sort
import sys


# 재귀적인 방법을 사용하면 Recursion Error가 유발된다.
# 백준 최대 재귀 깊이는 1000

# def quick_sort(array):
#     if len(array) <= 1:
#         return array
#     pivot = array[0]
#     tail = array[1:]
#     left = [x for x in tail if x <= pivot]
#     right = [x for x in tail if x > pivot]
#     return quick_sort(left) + [pivot] + quick_sort(right)

# 반복문을 사용하여 구현하자

def quick_sort(arr, start, end):
    if start >= end:
        return
    pivot = start
    left = start + 1
    right = end
    while left <= right:

        if left <= end and arr[left] < arr[pivot]:
            left += 1
        if right > start and arr[right] > arr[pivot]:
            right -= 1
        if left > right:
            arr[right], arr[pivot] = arr[pivot], arr[right]
        else:
            arr[left], arr[right] = arr[right], arr[left]
    quick_sort(arr, start, right - 1)
    quick_sort(arr, right + 1, end)


N = int(sys.stdin.readline().rstrip())
array = []
for _ in range(N):
    x = int(sys.stdin.readline().rstrip())
    array.append(x)

quick_sort(array, 0 , N -1)

for i in range(len(array)):
    print(array[i])
