// CORRECT
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int GIVEN = 1013;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, a, p, q, X;
		int result = 0;
		vector<int> seq;
		vector<int> pows;
		pows.push_back(1);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a;
			seq.push_back(a);
		}
		sort(seq.begin(), seq.end());
		cin >> p >> q >> X;
		for (int i = 1; i < N; i++) {
			pows.push_back((pows.back() * X) % GIVEN);
		}

		do {
			int sum = 0;
			for (int i = 0; i < N; i++) {
				sum += (seq[i] * pows[i]) % GIVEN;
			}
			sum = sum % GIVEN;
			if (sum >= p && sum <= q)
				result++;
		} while (next_permutation(seq.begin(), seq.end()));
		cout << result << '\n';
	}
	return 0;
}