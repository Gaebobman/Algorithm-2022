# https://www.acmicpc.net/problem/10162
# Greedy

T = int(input())
BUTTONS = [300, 60, 10]
result = [0, 0, 0]

while T >= 10:

    if T >= 300:
        result[0] += T // 300
        T %= 300
        if T == 0:
            for i in result:
                print(i, end=' ')
            break
    elif T >= 60:
        result[1] += T // 60
        T %= 60
        if T == 0:
            for i in result:
                print(i, end=' ')
            break
    elif T >= 10 :
        result[2] += T // 10
        T %= 10
        if T == 0:
            for i in result:
                print(i, end=' ')
            break
else:
    print(-1)
