#include <iostream>
#include <string>
#include<vector>

using namespace std;

int hamming_distance(string a, string b, int N) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i])
			result++;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		vector<string> alp;
		int M, N, L;
		string tmp, cipher;
		cin >> M >> N;
		for (int i = 0; i < M; i++) {
			cin >> tmp;
			alp.push_back(tmp);
		}
		cin >> L >> cipher;
		for (int i = 0; i <= L - N; i += N) {
			int min_diff = 129, min_idx = 0;
			for (int j = 0; j < M; j++) {
				int distance = hamming_distance(alp[j], cipher.substr(i, i + N), N);
				if (distance < min_diff) {
					min_diff = distance;
					min_idx = j;
				}
			}
			cout << char('A' + min_idx);
		}
		cout << '\n';
	}
	return 0;
}