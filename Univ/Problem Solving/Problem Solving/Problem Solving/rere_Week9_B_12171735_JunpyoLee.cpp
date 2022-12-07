// CORRECT
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string x, y;
		cin >> x >> y;
		int M = x.length();
		int N = y.length();
		vector<vector<int>> matrix(M + 1, vector<int>(N + 1, 0));
		for (int i = 0; i < M + 1; i++) {
			matrix[i][0] = i;
		}
		for (int j = 0; j < N + 1; j++) {
			matrix[0][j] = j;
		}
		for (int i = 1; i < M + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (x[i - 1] == y[j - 1])
					matrix[i][j] = matrix[i - 1][j - 1];
				else {
					matrix[i][j] = min({
						matrix[i - 1][j],
						matrix[i][j - 1],
						matrix[i - 1][j - 1]
						}) + 1;
				}
			}
		}
		cout << matrix[M][N] << '\n';
	}
	return 0;
}

