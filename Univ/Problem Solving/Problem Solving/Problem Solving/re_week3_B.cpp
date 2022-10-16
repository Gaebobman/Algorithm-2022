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
		int days = 0;	// �ҿ����� ī��Ʈ
		cin >> M;
		int carry = 0;		// �ڸ��ø��� ǥ��
		for (int i = M.length() - 1; i >= 0; i--) {
			// (int)'0' == 48
			int current_num = ((int)M[i]) - 48 + carry;
			// �ڸ��ø��� �� �� �� �߻��ߴ��� Ȯ��
			if (current_num == 10) {
				carry = 1;
				continue;
			}
			else {
				carry = 0;
			}


			if (current_num <= 5) {
				// ������ �ڸ�(MSB)�� �ƴ϶��
				// ���� �ڸ��� ����Ͽ� �뵿/����� ����
				if (i - 1 >= 0) {
					if ((int)M[i - 1] - 48 >= 5 && current_num == 5) {
						// �뵿
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