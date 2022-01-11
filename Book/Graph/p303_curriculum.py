N = int(input())
time = [0] * (N + 1)
for i in range(1, N + 1):
    data = list(map(int, input().split()))
    time[i] = data[0]
    for j in data[1:-1]:
       pass