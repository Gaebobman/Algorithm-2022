# 체스판위의 나이트가 이동할 수 있는 경우의 수를 출력하라
# ALPHABET_NUMBER (ex. a1 ,b3, ...) 이런식으로 주어짐

data = input()
# 좌표평면상에서 나타내기 쉽게 하기 위해 입력받은 데이터를 변환
x = (ord(data[0]) - 97 + 1)     # char to ASCII
y = int(data[1])                # char to integer

result = 0  # 움직일 수 있는 방향의 수

# Move Types: U2R1, U2L1, D2R1, D2L1, R2U1, R2D1, L2U1, L2D1
# dx = [1, -1, 1, -1, 2, 2, -2, -2]
# dy = [2, 2, -2, -2, 1, -1, 1, -1]
# 간략히 하면
move_types = [(1, 2), (-1, 2), (1, -2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)]

for i in range(len(move_types)):
    # 가능한 움직임이면 (체스판을 벗어나지 않으면)
    if 1 <= x + move_types[i][0] <= 8 and 1 <= y + move_types[i][1] <= 8:
        result += 1

print(result)
