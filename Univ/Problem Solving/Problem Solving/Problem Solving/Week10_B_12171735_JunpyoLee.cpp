// CORRECT
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct shark {
	int low;
	int high;
};

struct compare_high {
	bool operator()(const shark& a, const shark& b) {
		return a.high > b.high;
	}
};

struct compare_low {
	bool operator()(const shark& a, const shark& b) {
		return a.low > b.low;
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
		priority_queue<shark, vector<shark>, compare_low> temp;
		vector<int> tank;
		priority_queue<shark, vector<shark>, compare_high> q;
		int result = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			shark tmp = { A, B };
			temp.push(tmp);
		}
		for (int i = 0; i < M; i++) {
			cin >> C;
			tank.push_back(C);
		}
		sort(tank.begin(), tank.end());
		for (auto cur_tank = tank.begin(); cur_tank != tank.end(); cur_tank++) {
			while (!temp.empty()) {
				shark cur_shark = temp.top();
				if (cur_shark.low <= *cur_tank) {
					q.push(cur_shark);
					temp.pop();
				}
				else {
					break;
				}
			}
			while (!q.empty()) {
				shark sh = q.top(); q.pop();
				if (sh.high >= (*cur_tank)) {
					result++;
					break;
				}
			}
		}
		cout << result << '\n';
	}
	return 0;
}
