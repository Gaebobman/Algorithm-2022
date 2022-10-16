#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, M, N;
	cin >> T;
	while (T--) {
		int tmp;
		string command1, command2;
		cin >> M >> N;
		multiset<int, greater<int>> problems;
		multiset<int, greater<int>> ::iterator itr;
		for (int i = 0; i < M; i++) {
			cin >> tmp;
			problems.insert(tmp);
		}
		
		for (int i = 0; i < N; i++) {
			cin >> command1 >> command2;
			if (command1[0] == 'D') {
				if (command2[2] == 'n') {
					itr = prev(problems.end());
					problems.erase(itr);
				}
				else {
					itr = problems.begin();
					problems.erase(itr);
				}
			}
			else {
				problems.insert(stoi(command2));
			}
		}
		cout << *prev(problems.end()) << ' ' << *problems.begin() << '\n';
	}
	return 0;
}