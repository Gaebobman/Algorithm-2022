# Python 에서는 공백과 줄바꿈의 입력 처리를 다르게 해야한다.
import sys

print("데이터 갯수 n을 입력: ", end="")  # 줄바꿈 없는 출력
n = int(input())
print("공백으로 구별된 데이터 입력: ", end="")
data = list(map(int, input().split()))

data.sort(reverse=True)
print(data)

print("n, k, m 을 입력: ", end="")
n, k, m = map(int, input().split())
print(n, k, m)

# 줄바꿈으로 구별되는 문자는 int(input())으로 받으면 된다.


# 입력을 빠르게 받는 법

data = sys.stdin.readline().rstrip()  # 우측 문자 제거 (Enter 제거)
print(data)

# f string 사용법
Number = 29
print("정답은" + str(Number) + "이다")
print(f"정답은 {Number} 이다")
