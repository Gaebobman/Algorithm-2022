#include <iostream>
#include <vector>

using namespace std;

int gcd(int first, int second) {
	while (1) {
		int remain = first % second;
		if (remain == 0) {
			return second;
		}
		if (remain == 1) {
			return -1;
		}
		first = second;
		second = remain;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		vector<int> k1, k2;
		int n, m;
		int tmp;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			k1.push_back(tmp);
		}
		for (int i = 0; i < m; i++) {
			cin >> tmp;
			k2.push_back(tmp);
		}

		int sof1 = -1, sof2 = -1;

		for (int i = 0; i < m - 1; i++) {
			if (sof1 != -1) {
				sof1 = gcd(sof1, k2[i + 1]);
				continue;
			}
			sof1 = gcd(k2[i], k2[i + 1]);
			if (sof1 == -1)
				break;
		}

		for (int i = 0; i < n - 1; i++) {
			if (sof2 != -1) {
				sof2 = gcd(sof2, k1[i + 1]);
				continue;
			}
			sof2 = gcd(k1[i], k1[i + 1]);
			if (sof2 == -1)
				break;
		}

		if (sof1 != -1) {
			for (int i = 0; i < n; i++) {
				if (gcd(sof1, k1[i]) == sof1) {
					sof1 = -1;
					break;
				}
			}
		}

		if (sof2 != -1) {
			for (int i = 0; i < m; i++) {
				if (gcd(sof2, k2[i]) == sof2) {
					sof2 = -1;
					break;
				}
			}
		}

		if (n == 1)
			sof2 = k1[0];
		if (m == 1)
			sof1 = k2[0];
		if (sof1 == sof2) {
			sof1 = -1;
			sof2 = -1;
		}

		cout << sof1 << ' ' << sof2 << '\n';
	}
	return 0;
}