data = dict()
data['A'] = "Apple"
data['B'] = "Banana"
data['C'] = "Car"
data['D'] = "Data Structure"
print(data)

if 'B' in data:
    print("B is a key, data: ", data['B'])

# 키 데이터만 담은 리스트
key_list = data.keys()
# 값 데이터만 담은 리스트
value_list = data.values()
print(key_list)
print(value_list)

for key in key_list:
    print(data[key])