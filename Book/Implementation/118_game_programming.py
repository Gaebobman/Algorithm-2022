# N X M 의 맵 , 칸은 육지 또는 바다임, 캐릭터는 동서남북중 한 곳을 바라본다,
# 맵의 각 칸은 (A, B)로 나타냄 A는 북쪽으로 부터 떨어진 칸의 갯수, B는 서쪽으로부터 떨어진 칸의 개수
# 바다는 밟을수 없다

N, M = map(int, input().split())

x, y, direction = map(int, input().split())
heat_map = [[0] * N for _ in range(M)]  # 가본 땅
# 반시계 회전, 북동남서 순서, x는 북쪽으로 부터 남은 거리, y는 서쪽으로부터 남은 거리
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

moves = 0  # 탐색한 땅의 수

created_map = []
for i in range(N):
    created_map.append(list(map(int, input().split())))

turn = 1  # 회전 횟수
while True:

    # 4번 방향전환을 했으면
    if turn == 4:
        next_r_move_x = x - dx[direction]
        next_r_move_y = y - dy[direction]

        # 뒤로 갈 수 있는지 확인하고 가능하면 뒤로 이동
        if created_map[next_r_move_x][next_r_move_y] == 0:
            x = next_r_move_x
            y = next_r_move_y
            turn = 0
        # 못가면 종료
        else:
            break

    # 좌측 회전, 동시에 turn 1 증가, turn 4면 종료
    if direction - 1 == -1:
        direction = 3
        turn += 1
    else:
        direction -= 1
        turn += 1

    next_move_x = x + dx[direction]
    next_move_y = y + dy[direction]

    # 만약 바라보는 방향으로 이동 가능하다면
    if created_map[next_move_x][next_move_y] == 0 and heat_map[next_move_x][next_move_y] == 0:
        # 이동, heat_map 에 기록, 이동수 증가
        heat_map[next_move_x][next_move_y] = 1
        x = next_move_x
        y = next_move_y
        turn = 0
        moves += 1
        print("이동! 현 위치 [", x, y, ']')
        continue
    else:
        continue

print(moves)
