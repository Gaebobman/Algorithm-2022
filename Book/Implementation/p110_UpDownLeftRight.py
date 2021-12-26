import sys

N = int(sys.stdin.readline().rstrip())
data = list(input().split())

current_position = [1, 1]

for i in range(len(data)):
    if data[i] == "U":
        if 0 < current_position[0] - 1:
            current_position[0] -= 1

    elif data[i] == "D":
        if current_position[0] + 1 < N:
            current_position[0] += 1

    elif data[i] == "L":
        if 0 < current_position[1] - 1:
            current_position[1] -= 1

    elif data[i] == "R":
        if current_position[1] + 1 < N:
            current_position[1] += 1

print(current_position[0], current_position[1])
