// CORRECT
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void calculate(vector<int>& seq, int N, int p, int q, int X);
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int T, N, p, q, X;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> seq;
		for (int i = 0; i < N; i++) {
			cin >> q;
			seq.push_back(q);
		}
		sort(seq.begin(), seq.end());
		cin >> p >> q >> X;
		calculate(seq, N, p, q, X);
	}
	return 0;
}

void calculate(vector<int>& seq,int N, int p, int q, int X) {
	int result = 0;
	vector<int> power;
	power.push_back(1);
	for (int i = 1; i < N; i++) {
		power.push_back((power.back() * X) % 1013);
	}
	do {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += (seq[i] * power[i]) % 1013;
		}
		sum = sum % 1013;
		if (sum >= p && sum <= q)
			result++;
	} while (next_permutation(seq.begin(), seq.end()));
	cout << result << '\n';
}