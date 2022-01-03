d = [0] * 100
d[1] = 1
d[2] = 1

def fib(x):
    if x == 1 or x == 2:
        return 1

    for i in range(3, x + 1):
        d[i] = d[i - 1] + d[i - 2]

    return d[x]


print(fib(99))