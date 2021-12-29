array = [5, 6, 2, 7, 9, 1, 3, 4, 8]


def selection_sort():
    global array
    for i in range(len(array)):
        min_index = i  # 최소값의 인덱스
        for j in range(i + 1, len(array)):
            if array[min_index] > array[j]:
               min_index = j
        array[i], array[min_index] = array[min_index], array[i]


selection_sort()
print(array)
