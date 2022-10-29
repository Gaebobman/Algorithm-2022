#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, K, tmp;
		int from, to;
		vector<int> height;
		cin >> N >> M >> K;
		vector<int>* G = new vector<int>[N]; // Graph
		queue<int> Q;
		int* cost = new int[N];
		memset(cost, -1, N * sizeof(int));

		for (int i = 0; i < N; i++) {
			cin >> tmp;
			height.push_back(tmp);
		}
		int idx_of_han = 0;
		int min_height = height[0];
		for (int i = 1; i < N; i++) {
			if (height[i] < min_height) {
				min_height = height[i];
				idx_of_han = i;
			}
		}
		for (int i = 0; i < M; i++) {
			cin >> from >> to;
			G[from].push_back(to);
			G[to].push_back(from);
		}
		Q.push(idx_of_han);
		cost[idx_of_han] = 0;
		while (!Q.empty()) {
			int from_idx = Q.front(); Q.pop();	// Get front, pop
			for (int i = 0; i < G[from_idx].size(); i++) {
				int to_idx = G[from_idx][i];
				// Update Cost
				if (cost[to_idx] == -1) {
					cost[to_idx] = cost[from_idx] + 1;
					Q.push(to_idx);
				}
				else {
					cost[to_idx] = min(cost[to_idx], cost[from_idx] + 1);
				}
			}
		}
		for (int i = 0; i < K; i++) {
			cin >> tmp;
			if (tmp >= N)
				cout << "-1\n";
			else
				cout << cost[tmp] << '\n';
		}
		delete[] G;
		delete[] cost;
	}
	return 0;
}