n, k = map(int, input().split())

res = 0

while True:
    # 나누어 떨어질 때 까지 1씩 빼기
    target = (n // k) * k
    res += (n - target)
    n = target

    # n 이 k 보다 작다면 탈출
    if n < k:
        break
    n //= k
    res += 1

res += (n - 1)
print(res)

# Trivial Solution
# while n != 1:
#     if n % k == 0:
#         n /= k
#         res += 1
#     else:
#         n -= 1
#         res += 1
# print(res)
