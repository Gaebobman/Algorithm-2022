#include <iostream>
#include <string>
#include <vector>

using namespace std;
int hamming_distance(string first, string second, int N){
	int distance = 0;
	for (int i = 0; i < N; i++) {
		if (first[i] != second[i]) {
			distance++;
		}
	}
	return distance;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int M, N, L;
		vector<string> alp;
		string tmp, str;
		cin >> M >> N;
		for (int i = 0; i < M; i++) {
			cin >> tmp;
			alp.push_back(tmp);
		}
		cin >> L >> str;
		for (int i = 0; i <= L - N; i += N) {
			int min_len = 129, min_idx = 0;
			for (int j = 0; j < M; j++) {
				int distance = hamming_distance(str.substr(i, i + N), alp[j], N);
				if (distance < min_len) {
					min_len = distance;
					min_idx = j;
				}
			}
			cout << (char)('A' + min_idx);
		}
		cout << '\n';
	}
	return 0;
}