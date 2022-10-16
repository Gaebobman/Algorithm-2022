#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, K, W, V;
	cin >> T;
	while (T--) {
		vector<pair<int, int>> spice;	// 1. ����, 2. ����
		int result = 0;		// �� ����
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> W;
			spice.push_back({ W, 0 });
		}
		for (int i = 0; i < N; i++) {
			cin >> V;
			spice[i].second = V / spice[i].first;
		}
		sort(spice.begin(), spice.end(), compare);
		cout << endl;
		while (!spice.empty()) {
			if (K == 0)
				break;
			// 1. �Ѱ����� �� �� �� �ִ� ��� (K ������ ���)
			if (spice.back().first <= K) {
				result += spice.back().second * spice.back().first;
				K -= spice.back().first;
				spice.pop_back();
			} else {
			// 2. �Ѱ����� �� ����� ���(K�ʰ��� ���)
				result += spice.back().second * K;
				break;
			}
		}
		cout << result << '\n';
	}
}