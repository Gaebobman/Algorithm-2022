def binary_search(array, target):
    start = 0
    end = len(array)

    while start <= end:
        mid = (start + end) // 2
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None


arr = [1, 2, 5, 6, 10, 22, 31, 44]

print(binary_search(arr, 31))
