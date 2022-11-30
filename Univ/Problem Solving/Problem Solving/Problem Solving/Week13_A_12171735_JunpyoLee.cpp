// CORRECT
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_next(vector<pair<int, int>>& H, vector<int>& visited, int N);
void dfs(vector<vector<pair<int, int>>>& G, int node, vector<int>& visited);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, h, u, v;
		cin >> N >> M;
		vector<pair<int, int>> H;	// Height, Index
		vector<int> visited(N, 0);	// 0: Unvisited, 1: visited
		vector<vector<pair<int, int>>> G(N);	// Height, Index

		// 높이 입력
		for (int i = 0; i < N; i++) {
			cin >> h;
			H.push_back({ h, i });
		}
		// 그래프 입력
		for (int i = 0; i < M; i++) {
			cin >> u >> v;
			G[u].push_back({ H[v].first, v });
			G[v].push_back({ H[u].first, u });
		}
		// 높이순 정렬
		sort(H.begin(), H.end());
		for (int i = 0; i < N; i++) {
			sort(G[i].begin(), G[i].end());
		}
		// DFS 수행
		int node = get_next(H, visited, N);
		do {
			dfs(G, node, visited);
			node = get_next(H, visited, N);

		} while (node != -1);
	}
	return 0;
}

int get_next(vector<pair<int, int>>& H, vector<int>& visited, int N) {
	for (int i = 0; i < N; i++) {
		if (visited[H[i].second] == 0)
			return H[i].second;
	}
	return -1;
}

void dfs(vector<vector<pair<int, int>>>& G, int node, vector<int>& visited) {
	visited[node] = 1;
	cout << node << '\n';
	for (int i = 0; i < G[node].size(); i++) {
		if (visited[G[node][i].second] == 0)
			dfs(G, G[node][i].second, visited);
	}
}