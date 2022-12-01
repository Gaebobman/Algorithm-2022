// CORRECT
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int X, A, B;
		cin >> X >> A >> B;
		int pos_to = 0, pos_bi = X;
		while (pos_to != pos_bi) {
			if (pos_to + 2 * A >= pos_bi + A) {
				pos_bi += pos_bi - pos_to;
				pos_to = pos_bi;
			}
			else {
				pos_to += 2 * A;
				pos_bi += A + B;
			}
		}
		cout << pos_bi<<'\n';
	}
	return 0;
}