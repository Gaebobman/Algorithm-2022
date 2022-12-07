// CORRECT
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, K, h, u, v;
		vector<pair<int, int>> H;
		cin >> N >> M >> K;
		vector<vector<int>> G(N);
		vector<int> cost(N, -1);
		queue<int> Q;
		for (int i = 0; i < N; i++) {
			cin >> h;
			H.push_back({ h, i });
		}
		sort(H.begin(), H.end());
		for (int i = 0; i < M; i++) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		Q.push(H[0].second);
		cost[H[0].second] = 0;
		while (!Q.empty()) {
			u = Q.front(); Q.pop();
			for (int i = 0; i < G[u].size(); i++) {
				v = G[u][i];
				if (cost[v] == -1) {
					cost[v] = cost[u] + 1;
					Q.push(v);
				}
				cost[v] = min(cost[v], cost[u] + 1);
			}
		}
		for (int i = 0; i < K; i++) {
			cin >> u;
			if (u < N)
				cout << cost[u] << '\n';
			else
				cout << "-1\n";
		}
	}
	return 0;
}