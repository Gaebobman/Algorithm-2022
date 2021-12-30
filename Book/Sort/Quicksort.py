# Quick sort using Hoare Partition
# 5 7 9 0 3 1 6 2 4 8
# 5 4 9 0 3 1 6 2 7 8
# 5 4 2 0 3 1 6 9 7 8
# 5 4 2 0 3 1 6 9 7 8   # 크로스 발생 , 피벗 을 변경
# 1 4 2 0 3  |5|  6 9 7 8
# 1 0 2 4 3  |5|  6 9 7 8   # 크로스 발생
# 0 |  1 2 4 3      ### 생략

array = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(arr, start, end):
    # 원소가 하나면 종료
    if start >= end:
        return
    # 피벗 기준 좌 우 측 확인 하기
    pivot = start
    left = start + 1
    right = end

    while left <= right:
        # 좌측에서부터 피벗보다 큰 값 찾기
        while left <= end and arr[pivot] >= arr[left] :
            left += 1
        # 우측에서부터 피벗보다 작은 값 찾기
        while right > start and arr[pivot] <= arr[right] :
            right -= 1
        # 크로스 되었으면, 아래 실행 후 while 문 종료
        if left > right:
            arr[right], arr[pivot] = arr[pivot], arr[right]
        # 아니면 스왑 후 계속 실행
        else:
            arr[right], arr[left] = arr[left], arr[right]

    # 이제 크로스 된 상황에서 처리를 한다
    quick_sort(arr, start, right - 1)
    quick_sort(arr, right + 1, end)


quick_sort(array, 0, len(array) - 1)
print(array)
