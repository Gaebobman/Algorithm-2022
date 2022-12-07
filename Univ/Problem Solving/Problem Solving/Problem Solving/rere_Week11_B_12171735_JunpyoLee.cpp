// CORRECT
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		int result = 0;
		cin >> n >> m;
		int current_score = n;
		vector<int> table(n + 1);
		vector<int> score(m + 1);
		vector<int> opponent(m + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> table[i];
			score[table[i]] += current_score--;
			if (table[i] == 1 && i != 0) {
				opponent[table[i - 1]]++;
			}
		}
		while (1) {
			int first = max_element(score.begin() + 2, score.end()) - score.begin();
			if (score[first] < score[1])
				break;
			if (opponent[first] > 0) {
				opponent[first]--;
				score[first]--;
				score[1]++;
				result++;
			}
			else {
				first = max_element(opponent.begin() + 2, opponent.end()) - opponent.begin();
				if (opponent[first] == 0) {
					result = -1;
					break;
				}
				opponent[first]--;
				score[first]--;
				score[1]++;
				result++;
			}
		}
		cout << result << '\n';
	}
	return 0;
}