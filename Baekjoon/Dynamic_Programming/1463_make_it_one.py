# https://www.acmicpc.net/problem/1463
# DP

X = int(input())

d = [0] * (X + 4)
d[1] = 0
d[2] = 1
d[3] = 1


def make_one(x):
    if x == 1:
        return
    if x == 2 or x == 3:
        return

    for i in range(3, x + 1):
        d[i] = d[i - 1] + 1

        if i % 2 == 0:
            d[i] = min(d[i], d[i // 2] + 1)

        if i % 3 == 0:
            d[i] = min(d[i], d[i // 3] + 1)


make_one(X)
print(d[X])
