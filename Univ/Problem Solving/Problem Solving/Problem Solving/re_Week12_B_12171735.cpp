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
		set<pair<int, int>> stats;
		set<pair<int, int>>::iterator itr;	// Power, Floor
		vector<int> result;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p;
			stats.insert({ p, i + 1 });
			itr = stats.find({ p, i + 1 });
			itr--;

			if (itr == stats.end())
				cout << -1 << ' ';
			else
				cout << (*itr).second << ' ';
		} 
		cout << '\n';
	}
	return 0;
}
