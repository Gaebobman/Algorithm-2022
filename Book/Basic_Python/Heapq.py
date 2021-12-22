# Heap 을 위한 heapq, 다익스트라 알고리즘 등에서 Priority Queue 를 위해 사용
# Python 에서 Heap 은 Min Heap 임
import heapq


def heapsort(iterable):
    h = []
    result = []
    for value in iterable:
        heapq.heappush(h, value)
    for _ in range(len(h)):
        result.append(heapq.heappop(h))
    return result


res = heapsort([1, 3, 5, 6, 2, 3, 1, 7, 90])
print("minheap: ",res)

# 파이썬에서는 minheap만을 지원하므로 maxheap 으로 바꾸는 법
# 부호를 임시로 역전시키자

def maxheapsort(iterable):
    h = []
    result = []
    for value in iterable:
        heapq.heappush(h, -value)
    for _ in range(len(h)):
        result.append(-heapq.heappop(h))
    return result


res = maxheapsort([1, 3, 5, 6, 2, 3, 1, 7, 90])
print("maxheap: ", res)
