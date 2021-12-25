# https://www.acmicpc.net/problem/1541
# Greedy

data = input()

number = data.split('-')

for i in range(len(number)):
    # 만일 더하기가 존재 하면
    if '+' in number[i]:
        tmp = 0
        for x in number[i].split('+'):
            x = x.lstrip('0')
            tmp += int(x)
        number[i] = tmp
    else:
        number[i] = number[i].lstrip('0')  # 좌측에 붙은 0 제거

result = int(number[0])

for i in range(1, len(number)):
    result -= int(number[i])

print(result)
