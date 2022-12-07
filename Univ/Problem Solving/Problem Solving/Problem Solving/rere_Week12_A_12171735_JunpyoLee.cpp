// CORRECT
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int x, a, b;
		cin >> x >> a >> b;
		int pos_bi = x, pos_to = 0;
		while (pos_bi != pos_to) {
			if (pos_to + 2 * a >= pos_bi + a) {
				pos_bi += pos_bi - pos_to;
				pos_to = pos_bi;
			}
			else {
				pos_to += 2 * a;
				pos_bi += a + b;
			}
		}
		cout << pos_bi << '\n';
	}
	return 0;
}