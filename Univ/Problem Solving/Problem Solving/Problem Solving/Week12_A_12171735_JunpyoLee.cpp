#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, A, B, X;
	cin >> T;

	while (T--) {
		int pos_bi, pos_to = 0;
		cin >> X >> A >> B;
		pos_bi = X; 
		int result = 0;	
		int one_hop = A * 2;
		while (1) {
			if (pos_to + one_hop >= pos_bi + A) {
				result += (pos_bi - pos_to);
				break;
			}
			else {
				result += (A + B); 
				pos_to += one_hop;	
				pos_bi += (A + B);	
			}
		}
		cout << result + X << '\n';
	}
	return 0;
}

