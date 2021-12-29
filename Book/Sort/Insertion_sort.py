array = [5, 6, 2, 7, 9, 1, 3, 0, 4, 8]


def insertion_sort():
    global array
    # 두번째 부터 시작
    for i in range(1, len(array)):
        for j in range(i, 0, -1):
            if array[j] < array[j-1]:
                array[j], array[j - 1] = array[j - 1], array[j]
            else:
                break


insertion_sort()
print(array)