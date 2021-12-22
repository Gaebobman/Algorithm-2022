myset = set([1, 2, 3, 4, 5, 1, 2, 3])
print(myset)

myset = {1, 2, 3, 4, 5, 1, 2, 3}
print(myset)

# 집합 연산

a = set([1, 2, 3, 4, 5, 6])
b = set([3,4,6])

print("합집합:", a | b)    # 합집합
print("교집합:",a & b)    # 교집합
print("차집합:", a - b)    # 차집합

a.add(7)
print(a)
a.update([44, 32, 10])
print(a)
a.remove(1)
print(a)