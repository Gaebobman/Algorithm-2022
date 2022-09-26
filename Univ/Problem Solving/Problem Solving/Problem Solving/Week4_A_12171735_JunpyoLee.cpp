#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int> &b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 0, N = 0, K = 0;
	int tmp = 0;
	cin >> T;
	while (T--) {
		vector<pair<int, int>> spice;
		int total = 0;
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			spice.push_back(make_pair(tmp, 0));
		}
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			spice[i].second = tmp / spice[i].first;
		}
		sort(spice.begin(), spice.end(),compare);
		while (!spice.empty()) {
			if (spice.back().first <= K) {
				K -= spice.back().first;
				total += spice.back().second * spice.back().first;
				spice.pop_back();
			}
			else {
				total += spice.back().second * K;
				K -= spice.back().first;
				spice.pop_back();
				break;
			}

			if (K == 0) {
				break;
			}
		}
		cout << total << '\n';
	}
	return 0;
}