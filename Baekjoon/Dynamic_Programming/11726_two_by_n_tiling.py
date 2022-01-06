# https://www.acmicpc.net/problem/11726
# DP

N = int(input())
GIVEN_NUMBER = 10007
D = [0] * (N + 3)
D[1] = 1
D[2] = 2

for i in range(3, N + 1):
    D[i] = (D[i - 1] + D[i - 2]) % GIVEN_NUMBER
    # 세로로 긴 타일을 a, 가로로 긴 타일을 b라고 하면
    # i번 기준 1개의 새로운 공간이 생겼다면
    # a 하나를 써서 1개 짜리를 채우는 방법은 이전방법 X 1
    # b 2개를 써서 2개 짜리를 채우는 방법은 이전방법 X 1 + (1개짜리 채우는 방법 이지만)
    # 1개 짜리를 채우는 방법에서 a를 하나 썼다면 어차피 a를 또 하나 더 쓰기 때문에
    # b 2개를 쓰는 방법만 고려
print(D[N])
