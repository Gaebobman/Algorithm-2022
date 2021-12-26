# N X M 의 맵 , 칸은 육지 또는 바다임, 캐릭터는 동서남북중 한 곳을 바라본다,
# 맵의 각 칸은 (A, B)로 나타냄 A는 북쪽으로 부터 떨어진 칸의 갯수, B는 서쪽으로부터 떨어진 칸의 개수
# 바다는 밟을수 없다

N, M = map(int, input().split())

x, y, direction = map(int, input().split())
heat_map = [[0] * N for _ in range(M)]  # 가본 땅
# 반시계 회전, 북동남서 순서, x는 북쪽으로 부터 남은 거리, y는 서쪽으로부터 남은 거리
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

moves = 1  # 탐색한 땅의 수

created_map = []
for i in range(N):
    created_map.append(list(map(int, input().split())))

turn = 0  # 회전 횟수
while True:

    # 좌측 회전, 동시에 turn 1 증가, turn 4면 종료
    if direction - 1 == 0:
        direction = 3
        turn += 1
    else:
        direction -= 1
        turn += 1

    if turn == 4:
        break

    # 만약 바라보는 방향으로 이동 가능하다면

        # 이동, heat_map 에 기록, created_map 에 1로 기록

    # 이동 불가면 뒤로 이동

    # 사면초가 -> 종료



print(created_map)
