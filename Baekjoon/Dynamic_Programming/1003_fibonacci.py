# https://www.acmicpc.net/problem/1003
# DP
# Time Limit 0.25 => O(N)
#
def print_zero_one_count(number):
    print(D[number][0], D[number][1])


T = int(input())
data = []

for _ in range(T):
    d = int(input())
    data.append(d)

D = [[0, 0] for i in range(41)]

D[0] = [1, 0]
D[1] = [0, 1]


for i in range(2, 41):
    D[i][0] = D[i - 1][0] + D[i - 2][0]
    D[i][1] = D[i - 1][1] + D[i - 2][1]


for i in data:
    print_zero_one_count(i)
