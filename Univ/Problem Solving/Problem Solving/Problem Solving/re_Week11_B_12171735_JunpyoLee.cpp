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
		// int first_place;
		vector<int> table(n + 1);		// ��� (�� ��ȣ)
		vector<int> score(m + 1, 0);	// �� ���� ���� ����
		vector<int> opponent(m + 1, 0);	// ������ ������ ��뼱�� ���� {opponent[team]: �� ��?}
		for (int i = 1; i < n + 1; i++) {
			cin >> table[i];
			score[table[i]] += current_score--;
			// if current player is from inha, Then save opponents number(�ٷ� �տ� �ִ� ��)
			if (table[i] == 1 && i != 1)
				opponent[table[i - 1]]++;
		}
		
		while (1) {
			int first_place = max_element(score.begin() + 2, score.end()) - score.begin();
			if (score[first_place] < score[1])
				break;

			if (opponent[first_place] > 0) {
				opponent[first_place]--;
				score[1]++;
				score[first_place]--;
				result++;
			}
			else {
				first_place = max_element(opponent.begin() + 2, opponent.end()) - opponent.begin();
				if (opponent[first_place] == 0) {
					result = -1;
					break;
				}
				opponent[first_place]--;
				score[1]++;
				score[first_place]--;
				result++;
			}
		}
		cout << result << '\n';
	}
	return 0;
}