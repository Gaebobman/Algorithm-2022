#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

const int given = 1013;

using namespace std;
int calc(vector<int>& arr, int N, int X, int p, int q);
bool is_range(int number, int p, int q);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N, X, p, q;
		int tmp;
		int count = 0;
		vector<int> num_set;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			num_set.push_back(tmp);
		}
		cin >> p >> q >> X;
		sort(num_set.begin(), num_set.end());
		cout << calc(num_set, N, X, p, q)<<'\n';

	}
	return 0;
}

int calc(vector<int>& arr, int N, int X, int p, int q) {
	int arr_length = arr.size();
	int result = 0;
	vector <int> circulation; // 순환을 계산 (Array 길이 만큼)
	circulation.push_back(1);

	for (int i = 0; i < arr_length; i++) {
		int current = (circulation.back() * X) % given;
		circulation.push_back(current);
	}
	// 모든 순열을 확인한다.
	// (A * B) mod C = (A mod C * B mod C) mod C
	// (A + B) mod C = ((A mod C)+(B mod C))mod C
	do {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += arr[i] * circulation[i];
		}
		sum = sum % given;
		if (is_range(sum, p, q)) {
			result++;
		}
	} while (next_permutation(arr.begin(), arr.end()));

	return result;
}

bool is_range(int number, int p, int q) {
	if (number >= p && number <= q) {
		return true;
	}
	else
		return false;
}