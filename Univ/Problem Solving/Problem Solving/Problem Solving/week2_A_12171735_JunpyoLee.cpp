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
		// 1. ���ĺ����� �Է� ����
		for (int i = 0; i < M; i++) {
			cin >> tmp_str;
			alphabet.push_back(tmp_str);
		}
		// 2. �ջ�� Bit Sequence�� ���̿� ������ �Է¹��� 
		cin >> L >> bit_sequence;

		// 3. Brute force ����Ͽ� alphabet Vector�� ���ҿ� �� �����ϸ� ���� Distance�� ���� ���ĺ����� ġȯ
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