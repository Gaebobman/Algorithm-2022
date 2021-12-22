# https://docs.python.org/3/library/itertools.html
from itertools import permutations, combinations, product, combinations_with_replacement

data = ['A', 'B', 'C']
res = list(permutations(data, 3))
print(res)

res = list(combinations(data, 2 ))  # 2개를 뽑는 모든 조합
print(res)

res = list(product(data, repeat=2)) # 2개를 뽑는 모든 순열 
print(res)

res = list(combinations_with_replacement(data, 2))  # 2개를 뽑는 중복조합
print(res)