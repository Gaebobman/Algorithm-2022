#include <iostream>
#include <string>
#include <set>

using namespace std;


int main() {
	iostream::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, M, N;
	cin >> T;
	
	while (T--) {
		string command_1, command_2;
		multiset<int, greater<int>> S;
		multiset<int>::iterator itr;
		int tmp;
		cin >> M >> N;

		for (int i = 0; i < M; i++) {
			cin >> tmp;
			S.insert(tmp);
		}
		
		while (N--) {
			cin >> command_1 >> command_2;
			if (command_1[0] == 'D') {
				// Delete
				if (command_2.back() == 'n') {
					// Delete mi'n' 이면
					itr = (prev(S.end()));
					S.erase(itr);
				}
				else {
					// Delete ma'x' 이면
					itr = (S.begin());
					S.erase(S.begin());
				}
			}
			else {
				// Add
				S.insert(stoi(command_2));
			}
		}
		cout << *prev(S.end()) << ' ' << * S.begin() << '\n';
	}
	return 0;
}