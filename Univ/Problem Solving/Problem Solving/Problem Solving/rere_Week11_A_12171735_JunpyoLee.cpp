// CORRECT
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long ;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		ll N;
		cin >> N;
		int k = log2(N);
		ll zeros = k;
		ll ones = N;
		for (ll i = 2; i <= k; i++) {
			zeros += (i - 1) * pow(2, i - 2);
			ones += (i - 1) * pow(2, i - 2);
		}
		cout << zeros << ' ' << ones << '\n';
	}
	return 0;
}