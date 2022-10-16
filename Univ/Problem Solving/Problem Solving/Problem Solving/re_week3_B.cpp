#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		string M;
		int days = 0;	// 소요일을 카운트
		cin >> M;
		int carry = 0;		// 자리올림을 표시
		for (int i = M.length() - 1; i >= 0; i--) {
			// (int)'0' == 48
			int current_num = ((int)M[i]) - 48 + carry;
			// 자리올림이 한 번 더 발생했는지 확인
			if (current_num == 10) {
				carry = 1;
				continue;
			}
			else {
				carry = 0;
			}


			if (current_num <= 5) {
				// 마지막 자리(MSB)가 아니라면
				// 다음 자리를 고려하여 노동/사용을 결정
				if (i - 1 >= 0) {
					if ((int)M[i - 1] - 48 >= 5 && current_num == 5) {
						// 노동
						days += 5;
						carry = 1;
						continue;
					}
				}
				days += current_num;

			}
			else {
				days += 10 - current_num;
				carry = 1;
			}

		}
		days += carry;
		cout << days << '\n';
	}
	return 0;
}