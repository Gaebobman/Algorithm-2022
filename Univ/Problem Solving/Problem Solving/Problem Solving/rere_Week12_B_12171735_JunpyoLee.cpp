// CORRECT
#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, p;
		cin >> N;
		set<pair<int, int>> stat;	// power, index
		set<pair<int, int>>::iterator itr;
		for (int i = 1; i <= N; i++) {
			cin >> p;
			stat.insert({ p, i });
			itr = stat.find({ p, i });
			if (itr == stat.begin()) 
				cout << -1 << ' ';
			else
				cout << (*--itr).second << ' ';
		}
		cout << '\n';
	}
	return 0;
}