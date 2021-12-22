# if ~ else if

Cond = 100
res = "True" if Cond == 100 else "False"

print(res)

a = [1, 2, 3, 4, 5, 5, 5, 6, 7]
remove_set = {2, 5}

result = [i for i in a if i not in remove_set]
print(result)
