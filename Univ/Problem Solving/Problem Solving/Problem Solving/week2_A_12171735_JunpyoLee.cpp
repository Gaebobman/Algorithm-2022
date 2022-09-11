#include <iostream>
#include <string>
#include <vector>

using namespace std;

int hamming_distance(string a, string b, int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (a[i] != b[i])
			count++;
	}
	return count;
	// O(| length |) time (Max | length | == 128)
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// T: Test Cases (1~1000), M: Number of Alphabets (1~26), N: Bits (1~128), L: Length of sequence
	int T, M, N, L;
	string bit_sequence, tmp_str;
	cin >> T;
	while (T--) {
		vector<string> alphabet;
		vector<char> answer;
		cin >> M >> N;
		// 1. 알파벳들을 입력 받음
		for (int i = 0; i < M; i++) {
			cin >> tmp_str;
			alphabet.push_back(tmp_str);
		}
		// 2. 손상된 Bit Sequence의 길이와 원문을 입력받음 
		cin >> L >> bit_sequence;

		// 3. Brute force 사용하여 alphabet Vector의 원소와 비교 대조하며 가장 Distance가 작은 알파벳으로 치환
		for (int i = 0; i <= L - N; i += N) {
			int min_len = 129, min_idx = 0;
			int current_distance;
			for (int j = 0; j < M; j++) {
				current_distance = hamming_distance(bit_sequence.substr(i, i + N), alphabet[j], N);
				if (min_len >= current_distance ) {
					min_idx = j;
					min_len = current_distance;
				}
			}
			answer.push_back('A' + min_idx);
		}
		for (int i = 0; i < L / N; i++) {
			cout << answer[i];
		}

		cout << '\n';
		
	}
	return 0;
}