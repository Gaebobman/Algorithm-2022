from builtins import print

# Positive Integer
a = 1000
print(a)

# Negative Integer
a = -7
print(a)

# 0
a = 0
print(a)

# Real Number
# Positive RN
a = 157.93
print(a)

a = -1837.2
print(a)

a = 5.  # a = 5.0 (0이 생략됨)
print(a)

a = -.7  # a = -0.7 (정수부 0이 생략)
print(a)

# 10억의 지수표현

a = 1e9
print(a)

a = 75.25e1  # 752.5
print(a)
a = 3954e-3  # 3.954
print(a)

# Floating-point round()

a = .3 + 0.6
print(round(a, 4))  # 소수점 5번째 자리에서 반올림 round (x, n) => n + 1 자리에서 반올림함

# 수 연산자
a = 7
b = 3
print(a / b)
print(a % b)
print(a // b)   # 몫 연산자 //
print(2 ** 10)  # 거듭제곱 연산자 **   2^10
