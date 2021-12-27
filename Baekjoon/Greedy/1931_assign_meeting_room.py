# https://www.acmicpc.net/problem/1931
# Greedy, Activity selection problem (https://en.wikipedia.org/wiki/Activity_selection_problem)
import sys

N = int(sys.stdin.readline().rstrip())
# 입력받을 데이터의 이차원 리스트
data = []
result = 0
for _ in range(N):
    start, end = map(int, input().split())
    data.append([start, end])

# 끝나는 시간 순 정렬 후, 시작시간으로 정렬
data.sort(key=lambda time: (time[1], time[0]))

# 마지막으로 검사한 회의의 끝나는 시간 (초기값 0)
end_time = 0

for i in range(N):

    if data[i][0] >= end_time:
        result += 1
        end_time = data[i][1]

print(result)
