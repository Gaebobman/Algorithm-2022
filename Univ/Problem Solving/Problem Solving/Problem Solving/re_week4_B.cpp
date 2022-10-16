/* Not finished */

#include <iostream>
#include <vector>

using namespace std;
int dfs(vector<vector<int>>& G,int depth[]) {

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int n = 0, m, u, v;
		vector<int> virus;
		cin >> n >> m;
		vector<vector<int>> G(n + 1);
		int* depth;		// Node의 Depth를 추적
		memset(&depth, 0, n + 1);
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 0; i < m; i++) {
			cin >> v;
			virus.push_back(v);
		}
		free(depth);
	}


	return 0;
}