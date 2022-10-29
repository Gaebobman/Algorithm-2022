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
		string m;
		cin >> m;
		int carry = 0;
		int result = 0;
		for (int i = m.size() - 1; i >= 0; i--) {
			int current_num = m[i] - '0';
			current_num += carry;
			if (current_num == 10) {
				carry = 1;
				continue;
			}
			else {
				carry = 0;
			}

			if (current_num >= 6) {
				result += 10 - current_num;
				carry = 1;
			}
			else {
				if (current_num == 5) {
					if (i - 1 >= 0) {
						if (m[i - 1] - '0' >= 5) {
							carry = 1;
						}
						result += 5;
					}
					else {
						result += 5;
					}
				}
				else {
					result += current_num;
				}
			}

		}
		cout << result + carry << '\n';
	}

	return 0;
}