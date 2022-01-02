def binary_search(array, target):
    start = 0
    end = len(array)

    while start <= end:
        mid = (start + end) // 2
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    return None


N = int(input())
parts = list(map(int, input().split()))
M = int(input())
orders = list(map(int, input().split()))

parts.sort()

for part in orders:
    if binary_search(parts, part) is not None:
        print("yes", end=' ')
    else:
        print("no", end=' ')
