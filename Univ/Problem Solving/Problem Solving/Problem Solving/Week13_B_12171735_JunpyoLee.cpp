// CORRECT
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;
const int INF = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, Q, u, v, w;
		cin >> N >> M >> Q;
		// Set adj Matrix
		int** G = new int*[N];
		for (int i = 0; i < N; i++) {
			G[i] = new int[N];
		}
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (i == j)
					G[i][j] = 0;
				else
					G[i][j] = INF;
			}
		}
		// Input Cost
		for (int i = 0; i < M; i++) {
			cin >> u >> v >> w;
			G[u][v] = w;
			G[v][u] = w;
		}
		// Floyd Warshall
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N; j++) {
				if (j == k)
					continue;
				for (int i = 0; i < N; i++) {
					if (i == k)
						continue;
					if (G[i][k] != INF && G[k][j] != INF) {
						G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
					}
				}
			}
		}

		// Query
		for (int i = 0; i < Q; i++) {
			cin >> u >> v;
			cout << G[u][v]<<'\n';
		}
		// Delete Matrix
		for (int i = 0; i < N; i++)
			delete[] G[i];
		delete[] G;
	}
	return 0;
}