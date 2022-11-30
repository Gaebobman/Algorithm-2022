#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, A, B, X;
	cin >> T;
	while (T--) {
		cin >> X >> A >> B;
		int turn = X / (A - B) - 1;
		int pos_to, pos_bi;
		int result = 0;
		int gap = X % (A - B);

		while (gap > A) {
			gap -= A - B;
			cycle++;
		}


		if (X < 2*A) {
			result = X;
		}
		else if (X + turn * A + (turn -1) * B == turn *2 * A) {
			result = turn * 2 * A;
		} 
		else{
			// 일반적인 경우
			pos_to = A * 2 * turn;
			pos_bi = X + turn * (A + B);
			result = pos_bi + (pos_bi - pos_to);
		}

		cout << result << '\n';
	}
	return 0;
}