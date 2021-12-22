i = 1
res = 0

while i <= 10:
    if i % 2 == 1:
        res += i
    i += 1

print(res)

# for 문

res = 0

for i in range(1, 10):
    res += i

print("for문 res", res)

scores = [20, 40, 29, 10, 48]
for i in range(5):
    if scores[i] >= 20:
        print(i, "번은 20이상 입니다.")
