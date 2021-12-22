mystring = 'HI HI HI'
print(mystring)

mystring = "큰따옴표 안에 '작은 따옴표' "
print(mystring)

mystring = '작은 따옴표 안에 "큰 따옴표" '
print(mystring)

mystring = "\"무제한\" 으로 \"사용 하기\""
print(mystring)

a = "앞 문자열"
b = "뒤 문자열"
print(a + " " + b)
print((a + ", ") * 3)  # 문자열이 쉼표와 함께 3번 반복하여 나온다

a = "123456"
print(a[2: 4])  # 문자열은 리스트로 처리되므로 슬라이싱도 된다
