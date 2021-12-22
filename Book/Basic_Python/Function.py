# How to use function in python

# def function(args):
#     perform something
#     return X      없어도 됨

def pow(a, b):
    print(a ** b)


pow(b=10, a=2)

# global Keyword

a = 0


def myfunc():
    global a    # global 키워드로 함수 외부에서 선언된 변수 사용
    a += 1


for i in range(10):
    myfunc()

print(a)

# Lambda Expression
print((lambda a, b: a ** b)(5, 3))
