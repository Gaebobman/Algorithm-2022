# Disjoint Set

def find_team(team, x):
    if team[x] != x:
        team[x] = find_team(team, team[x])
    return team[x]


def union_team(team, a, b):
    a = find_team(team, a)
    b = find_team(team, b)

    if a < b:
        team[b] = a
    else:
        team[a] = b


UNION = 0  # 팀 합치기 연산 번호
CHECK_TEAMMATE = 1  # 같은 팀 확인 연산 번호

N, M = map(int, input().split())

team = [i for i in range(N + 1)]  # Parent 초기화

for _ in range(M):
    func, a, b = map(int, input().split())
    if func == UNION:
        union_team(team, a, b)
    elif func == CHECK_TEAMMATE:
        if find_team(team, a) == find_team(team, b):
            print("YES")
        else:
            print("NO")





