# https://www.acmicpc.net/problem/10610
N = list(input())
none_zero_flag = True
sum_of_list = 0
for i in N:
    sum_of_list += int(i)
    if i == '0':
        none_zero_flag = False


if sum_of_list % 3 != 0 or none_zero_flag:
    print(-1)
else:
    N.sort(reverse=True)
    for i in N:
        print(i, end='')
