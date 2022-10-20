#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int M, N, tmp;
		multiset<int, greater<int>> prob;
		multiset<int, greater<int>>::iterator itr;
		cin >> M >> N;
		for (int i = 0; i < M; i++) {
			cin >> tmp;
			prob.insert(tmp);
		}

		for (int i = 0; i < N; i++) {
			string command1, command2;
			cin >> command1 >> command2;
			if (command1[0] == 'D') {
				if (command2.back() == 'x') {
					itr = prob.begin();
					prob.erase(itr);
				}
				else {
					itr = prev(prob.end());
					prob.erase(itr);
				}
			}
			else {
				prob.insert(stoi(command2));
			}
		}
		cout << *prev(prob.end()) << ' ' << *prob.begin() << '\n';
	}

	return 0;
}