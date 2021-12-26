# https://www.acmicpc.net/problem/1541
# Greedy

data = input()

number = data.split('-')    # 더한것을 빼는것이 유리하다.

for i in range(len(number)):
    # 만일 더하기가 존재 하면
    if '+' in number[i]:
        tmp = 0
        for x in number[i].split('+'):
            x = x.lstrip('0')   # 좌측에 붙은 0 제거
            tmp += int(x)
        number[i] = tmp
    else:
        number[i] = number[i].lstrip('0')  # 단일 숫자면 좌측에 붙은 0 제거

result = int(number[0])

for i in range(1, len(number)):
    result -= int(number[i])

print(result)
