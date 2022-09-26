#include <iostream>
#include <vector>

using namespace std;

struct sector {
	int vertex;
	int parent;
	vector <sector> child;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0, n = 0, m = 0;

	cin >> T;

	while (T--) {
		cin >> n >> m;
		vector<int> infected;
		int* parent;
		vector<vector<int>> vertx;
		int x, y;
		memset(&parent, 0, n + 1);
		parent[1] = 1;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;

		}
		/*
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			matrix[x][y] = 0;
			matrix[y][x] = 0;
		}
		for (int i = 0; i < m; i++) {
			cin >> x;
			for (int i = 1; i <= n; i++) {
				if (matrix[x][i] == 0) {
					matrix[x][i] == -1;
				}
				if (matrix[i][x] == 0) {
					matrix[i][x] == -1;
				}
			}
			parent[x] = x;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (matrix[i][j] == 0) {
					if (parent[i] == 0) {
						parent[i] = 1;
					}
				}
				else {

				}
			}
		}

		*/


	}
	return 0;
}