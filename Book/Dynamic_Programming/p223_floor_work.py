# DP
# b = 2 X 1, a = 1 X 2, c = 2 X 2
#
# 1 = b
# 2 = bb/ aa / c
# 3 = bbb/ baa / aab / bc / cb
# 4 = bbbb / bbaa/ baab / aabb / bbc / bcb / cbb  / aaaa / cc

# 좌측 i - 1 개가 채워져 있다면 2 X 1 블록을 사용하는 한개의 방법
# 좌측 i - 2 개가 채워져 있다면 1 X 2 2개 또는 2 X 2 블록을 사용하는 2가지 방법
# 1, 2, 3, 4, ~ ,N 까지 확인하며
# D[1] = 1
# D[2] = 3
# D[3] = D[2] + D[1] * 2 == 3 + 2
# ...
# D[i] = D[i - 1] + D[i - 2] * 2 (단, i >=3)

GIVEN_NUMBER = 796796  # 이걸로 나눈 나머지를 출력하라고 했음

N = int(input())

D = [0] * (N + 1)  # DP TABLE
D[1] = 1
D[2] = 3

for i in range(3, N + 1):
    D[i] = (D[i - 1] + (D[i - 2] * 2)) % GIVEN_NUMBER

print(D[N])
