#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int levenshtein_distance(string x, string y);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string x, y;
		cin >> x >> y;
		cout << levenshtein_distance(x, y) << '\n';
	}
	return 0;
}

int levenshtein_distance(string a, string b) {
	int m = a.length();
	int n = b.length();
	// Init Matrix (m by n size)
	int** D = new int* [m + 1];
	for (int i = 0; i < m + 1; i++) {
		D[i] = new int[n + 1];
		for (int j = 0; j < n + 1; j++) {
			if (j == 0)
				D[i][j] = i;
			else if (i == 0)
				D[i][j] = j;
			else
				D[i][j] = 0;
		}
	}

	// Empty String과의 거리를 세팅
	for (int i = 1; i <= m; i++) {
		D[i][0] = i;
	}
	for (int j = 1; j <= n; j++) {
		D[0][j] = j;
	}

	// j -> axis Y 
	// i -> axis X
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			if (a[i - 1] == b[j - 1]) {
				D[i][j] = D[i - 1][j - 1];
			}
			else {
				D[i][j] = min({
				D[i - 1][j],
				D[i][j - 1],
				D[i - 1][j - 1]
					}) + 1;
				// deletion
				// insertion
				// substitution
			}
		}
	}
	int result = D[m][n];
	// Delete Matrix
	for (int i = 0; i < m + 1; i++) {
		delete[] D[i];
	}
	delete[] D;

	return result;
}