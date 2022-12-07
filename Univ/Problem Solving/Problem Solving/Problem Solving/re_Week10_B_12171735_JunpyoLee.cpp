// CORRECT
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct compare_high {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

struct compare_low {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, A, B, C;
		int result = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare_low> shark;
		vector<int> tank;
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare_high> Q;
		pair<int, int> tmp_shark;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			shark.push({ A, B });
		}
		for (int i = 0; i < M; i++) {
			cin >> C;
			tank.push_back(C);
		}
		sort(tank.begin(), tank.end());
		for (int i = 0; i < M; i++) {
			while (!shark.empty()) {
				tmp_shark = shark.top();
				if (tmp_shark.first <= tank[i]) {
					Q.push(tmp_shark);
					shark.pop();
				}
				else
					break;
			}
			while (!Q.empty()) {
				tmp_shark = Q.top(); Q.pop();
				if (tmp_shark.second >= tank[i]) {
					result++;
					break;
				}
			}
		}
		cout << result << '\n';
	}
	return 0;
}