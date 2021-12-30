def count_sort(arr):
    count_array = [0] * (max(arr) + 1)

    for i in range(len(arr)):
        count_array[arr[i]] += 1

    for i in range(len(count_array)):
        for j in range(count_array[i]):
            print(i, end=' ')


array = [7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2]

count_sort(array)