n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort()

first = data[len(data) - 1]
second = data[len(data) - 1]

res = 0

# Fast Solution
# 반복적인 것을 찾아서 더하자
count_of_first_number = int(m / (k + 1)) * k    # 가장 큰 수가 몇 번 나올까
count_of_first_number += m % (k + 1)            # 나머지

res = count_of_first_number * first
res += (m - count_of_first_number) * second

# Trivial Solution
# while m > 0:
#     for i in range(1, k):
#         if m > 0:
#             res += first
#             m -= 1
#     if m > 0:
#         res += second
#         m -= 1

print(res)
