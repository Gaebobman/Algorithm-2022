
X = int(input())

d = [0] * (X + 1)
d[1] == 0
d[2] == 1
d[3] == 1


def make_one(x):
    if x == 1:
        return 0
    if x == 2 or x == 3 or x == 5:
        return 1

    for i in range(4, x + 1):
        d[i] = d[i - 1] + 1

        if i % 2 == 0:
            d[i] = min(d[i], d[i // 2] + 1)

        if i % 3 == 0:
            d[i] = min(d[i], d[i // 3] + 1)

        if i % 5 == 0:
            d[i] = min(d[i], d[i // 5] + 1)


make_one(X)
print(d[X])
