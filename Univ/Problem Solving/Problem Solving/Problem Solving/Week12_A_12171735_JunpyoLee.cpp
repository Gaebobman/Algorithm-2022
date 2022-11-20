#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, A, B, X;
	cin >> T;
	// X: 비룡 이미 간 거리
	// A: 한번에 달릴 시간
	// B: 쉬는 시간
	while (T--) {
		// 한번에 이동하는 거리 == A * 2;
		// 한번에 이동 가능거리가 나오면 그때 계산
		// 초당 1미터씩 가까워짐
		int pos_bi, pos_to = 0;
		cin >> X >> A >> B;
		pos_bi = X; // 초기 비룡의 위치 저장
		int result = 0;	// 걸린  시간
		int one_hop = A * 2;
		while (pos_bi != pos_to) {
			// 이번 턴에 잡을 수 있으면
			if (pos_to + one_hop >= pos_bi + A) {
				result += (pos_bi - pos_to);
				break;
			}
			else {
				// 못잡고 다음턴으로 넘어가면
				result += (A + B); // 한번 HOP, 휴식
				pos_to += one_hop;	// 위치 업데이트
				pos_bi += (A + B);	// 도망
			}
		}

		cout << result + X << '\n';
	}
	return 0;
}