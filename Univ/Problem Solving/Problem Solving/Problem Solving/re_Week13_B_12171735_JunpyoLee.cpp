// CORRECT
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, Q, u, v, w;
		cin >> N >> M >> Q;
		vector<vector<int>> G(N, vector<int>(N, INT_MAX));
		for (int i = 0; i < M; i++) {
			cin >> u >> v >> w;
			G[u][v] = w; G[v][u] = w;
		}
		// j -> K -> i
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N; j++) {
				if (j == k)
					continue;
				for (int i = 0; i < N; i++) {
					if (i == k)
						continue;
					if (G[i][k] != INT_MAX && G[k][j] != INT_MAX)
						G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
				}
			}

		}

		for (int i = 0; i < Q; i++) {
			cin >> u >> v;
			cout << G[u][v] << '\n';
		}
	}
	return 0;
}