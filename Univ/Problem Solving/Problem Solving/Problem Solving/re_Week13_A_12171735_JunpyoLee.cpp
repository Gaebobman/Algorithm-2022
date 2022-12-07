// CORRECT
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_next(vector<pair<int, int>>& H, vector<int>& visited, int N);
void dfs(vector<vector<pair<int, int>>>& G, int node, vector<int>& visited);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, h, u, v;
		cin >> N >> M;
		vector<pair<int, int>> H;	// Height, Index
		vector<int> visited(N, 0);	// 0: Unvisited, 1: visited
		vector<vector<pair<int, int>>> G(N);	// Height, Index
		for (int i = 0; i < N; i++) {
			cin >> h;
			H.push_back({ h , i });
		}
		for (int i = 0; i < M; i++) {
			cin >> u >> v;
			G[u].push_back({ H[v].first, v });
			G[v].push_back({ H[u].first, u });
		}
		sort(H.begin(), H.end());
		for (int i = 0; i < N; i++) {
			sort(G[i].begin(), G[i].end());
		}
		int node = get_next(H, visited, N);
		do {
			dfs(G, node, visited);
			node = get_next(H, visited, N);
		} while (node != -1);
	}
	return 0;
}

int get_next(vector<pair<int, int>>& H, vector<int>& visited, int N) {
	for (auto node : H) {
		if (visited[node.second] == 0)
			return node.second;
	}
	return -1;
}

void dfs(vector<vector<pair<int, int>>>& G, int node, vector<int>& visited) {
	visited[node] = 1;
	cout << node << '\n';
	for (auto next : G[node]) {
		if (visited[next.second] == 0)
			dfs(G, next.second, visited);
	}
}
