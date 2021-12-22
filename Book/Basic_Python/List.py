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

n = 3
m = 4

array = [[0] * m for _ in range(n)]
print(array)

# !!! 주의 !!! List Comprehension 이 반드시 필요한 경우
print()
array = [[0] * m] * n
print(array)

array[1][1] = 5
print(array)

a = [1, 7, 6, 2, 8, 0]
print("리스트: ", a)

a.append(10)
print("append(10) 이후 리스트: ", a)

a.sort()
print("sort() 이후 리스트", a)

a.sort(reverse=True)
print("내림차순 정렬, sort(reverse=True) 이후 리스트: ", a)

a.reverse()
print("원소 뒤집기", a)

a.insert(2, 3)      # O(N)소요
print("idx 2에 3넣기", a)

print("3의 갯수 세기", a.count(3))

a.remove(3)     # O(N)소요, 하나만 제거됨
print("3 삭제", a)

# 특정 원소를 모두 제거하기
a = [1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10]
remove_set = {3, 5}

result = [i for i in a if i not in remove_set]
