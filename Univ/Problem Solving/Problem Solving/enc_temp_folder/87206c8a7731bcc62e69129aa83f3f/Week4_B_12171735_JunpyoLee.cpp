#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0, n = 0, m = 0;

	cin >> T;

	while (T--) {
		cin >> n >> m;

		vector<vector<int>> graph(n + 1);
		vector<int> infected;
		//int* root;
		int x, y;
		//memset(&root, 0, sizeof(int) * (n + 1));
		//root[1] = 1;
		for (int i = 0; i < n - 1; i++) {
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		for (int i = 0; i < m; i++) {
			cin >> x;
			infected.push_back(x);
		}

		for (int i = 1; i <= n; i++) {
			cout << i << " 에 연결된 것: ";
			for (int j = 0; j < graph[i].size(); j++) {
				cout << graph[i][j] << ' ';
			}
			cout << '\n';
		}
		//free(root);
	}
	return 0;
}