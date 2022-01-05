# 주어진 칼로 떡을 썰고 남은 길이를 반환하는 함수
def chop_rice(array, knife_len):
    length = 0
    for i in array:
        if i > knife_len:
            length += i - knife_len
    # print("현재 길이: ", length)
    return length


def binary_search(data, target):
    start = 0
    end = max(data)
    mid = 0
    while start <= end:
        mid = (start + end) // 2
        # data 중에서 가장 큰 값을 기준으로 바이너리 서치를 수행
        if chop_rice(data, mid) > target:
            start = mid + 1
            # print("찾는 값보다 작다", start, "부터", end, "까지 한다")
        else:
            end = mid - 1
            # print("찾는 값보다 크다", start, "부터 시작한다", end, "까지 한다")
    return mid


N, M = map(int, input().split())
data = list(map(int, input().split()))

print(binary_search(data, M))
