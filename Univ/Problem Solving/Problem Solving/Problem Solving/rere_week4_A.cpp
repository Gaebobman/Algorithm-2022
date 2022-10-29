#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N, K, w, v;
		int result = 0;
		cin >> N >> K;
		vector<pair<int, int>> spice;	// 가격, 무게
		for (int i = 0; i < N; i++) {
			cin >> w;
			spice.push_back({ 0, w });
		}
		for (int i = 0; i < N; i++) {
			cin >> v;
			spice[i].first = v / spice[i].second;
		}
		sort(spice.begin(), spice.end(), compare);
		while (!spice.empty()) {
			if (spice.back().second <= K) {
				result +=  spice.back().first * spice.back().second;
				K -= spice.back().second;
				spice.pop_back();
			}else{
				result += spice.back().first * K;
				break;
			}
		}
		cout << result << '\n';
	}
	return 0;
}