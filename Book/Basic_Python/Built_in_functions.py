# sum() 은 iterable 객체의 합을 리턴
res = sum([1, 2, 3, 4, 5])
print("sum()", res)

res = min(32, 16, 8, 20, 5)
print("min()", res)

res = max(32, 16, 8, 20, 5)
print("max()", res)

# eval()은 수식을 계산함
res = eval("(22 * 3) + 10")
print("eval(\"(22 * 3) + 10)\" 의 결과", res)

# sorted()는 Iterable 객체를 sort 하지요
res = sorted([9, 20, 19, 2, 7, 22])
print(res)
res = sorted([9, 20, 19, 2, 7, 22], reverse=True)  # reverse 속성으로 뒤집기
print(res)

# 리스트나 튜플의 기준에 따라서 정렬을 수행

res = sorted([("나", 100), ("너", 80), ("쟤", 98)], key= lambda x: x[1], reverse=True)
print(res)

data = [2021, 1998, 2017, 2018]
data.sort()
print(data)