#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 0;
	string M;
	int days = 0;
	cin >> T;
	while (T--) {
		cin >> M;
		int c = 0;
		int carry = 0;
		c = int(M.length());
		for(int i = c - 1; i >= 0; i--){
			int tmp = (int)M[i] - 48;

			if (carry != 0) {
				tmp += carry;
				if (tmp >= 10) {
					tmp -= 10;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}

			if (tmp <= 5) {
				if (i - 1 >= 0) {
					if ((int)M[i - 1] - 48 >= 5 && tmp == 5) {
						days += tmp;
						carry = 1;
						continue;
					}
				}
				
				days += tmp;
				
			}
			else {

				days += 10 - tmp;
				carry = 1;
			}
		}
		days += carry;
		cout << days << '\n';
		days = 0;
	}
	return 0;
}