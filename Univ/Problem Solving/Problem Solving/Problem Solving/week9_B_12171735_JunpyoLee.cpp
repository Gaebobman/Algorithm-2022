#include <iostream>
#include <string>
#include <vector>

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
		cout << levenshtein_distance(y, x) << '\n';
	}
	return 0;
}

int levenshtein_distance(string x, string y) {
	int m = x.length();
	int n = y.length();

	// Init Matrix (m by n size)
	int** D = new int* [m + 1];
	for (int i = 0; i < m; i++) {
		D[i] = new int[n + 1];
		for (int j = 0; j < n; j++) {
			if (j == 0)
				D[i][j] = i;
			else if (i == 0)
				D[i][j] = j;
			else
				D[i][j] = 0;
		}
	}
	for (int j = 1; j <) {

	}






	int result = D[m][n];
	// Delete Matrix
	for (int i = 0; i < m + 1; i++) {
		delete[] D[i];
	}
	delete[] D;

	return result;
}