# Python 에서는 deque 로 Queue 를 구현하자
# deque 는 stack 이나 queue 의 기능을 포함한다.
from collections import deque, Counter

data = deque([2, 3, 4])
data.appendleft(1)
data.append(5)

print(data)
print(list(data))

counter = Counter(['a', 'b', 'c', 'a', 'd', 'c', 'b', 'a'])
print("a 등장 횟수:", counter['a'])
print("b 등장 횟수:", counter['b'])
print("c 등장 횟수:", counter['c'])
print(dict(counter))    # Dictionary
print(counter.keys())