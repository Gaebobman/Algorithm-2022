# 파이썬의 List는  C++ 의 Vector와 유사

a = [1, 2, 3, 4, 5, 6]
print(a)  # 모든 원소 출력
print(a[4])  # 4번 idx에 접근

a = list()  # 빈 리스트 선언 1
print(a)
a = []  # 빈 리스트 선언 2
print(a)

# TIP: list를 N 만큼 0으로 초기화
n = 10
a = [0] * n
print(a)

# 이러면 [1, 2, 1, 2, 1, 2, 1, 2, 1, 2]
a = [1, 2] * 5
print(a)

a = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print(a[-1])  # 뒤에서 1번째 원소 9 출력
print(a[-3])  # 뒤에서 3번째 원소 7 출력
a[3] = 7  # idx 3번 7로 변경
print(a)

# list Slicing
print(a[1: 4])  # idx 2번부터 4번까지 슬라이싱
# !!!주의!!! list[N : M] 는 N+1번부터 M번 까지라는 의미

# range 함수
# range(N) => range(0, N) => 0, 1, 2, ... , N-1
array = [i for i in range(0, 20, 2)]
print(array)

array = [i for i in range(20, 0, -2)]
print(array)

# list Comprehension (리스트 컴프리헨션): 리스트 초기화하는 방법 중 하나

# 0부터 19까지의 수 중에서 홀수만 포함하는 리스트

array = [i for i in range(20) if i % 2 == 1]

print(array)

array = [i * i for i in range(1, 10)]
print(array)

# List Comprehension 으로 2차원 List 초기화

