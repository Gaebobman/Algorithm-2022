# Sorted array 에서 특정 원소를 찾을 때 사용
from bisect import bisect_left, bisect_right

a = [1, 8, 8, 8, 20, 21, 22]
x = 8

print(bisect_left(a, x))
print(bisect_right(a, x))


# 값이 [left_value, right_value] 인 데이터의 개수를 반환하는 함수
def count_by_range(a, left_value, right_value):
    right_index = bisect_right(a, right_value)
    left_index = bisect_left(a, left_value)
    return right_index - left_index


a = [1, 2, 3, 3, 4, 4, 4, 5, 5, 10]

print(count_by_range(a, 4, 4))
print(count_by_range(a, 1, 3))
