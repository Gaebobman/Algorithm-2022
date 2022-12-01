// WRONG
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, p;
		vector<pair<int, int>> stat_idx;
		set<pair<int, int>> stat_set;
		set<pair<int, int>>::iterator itr;
		vector<int> result;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p;
			stat_idx.push_back({ p, i + 1});
			stat_set.insert({ p, i + 1});
			itr = stat_set.find({ p, i + 1 });
			itr--;
			if (itr == stat_set.end()) {
				result.push_back(-1);
			}
			else {
				result.push_back((*itr).second);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}