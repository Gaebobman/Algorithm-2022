// CORRECT
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void levenshtein_distance(string X, string Y);

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string X, Y;
		cin >> X >> Y;
		levenshtein_distance(X, Y);
	}
	return 0;
}

void levenshtein_distance(string X, string Y) {
	int m = X.length();
	int n = Y.length();
	// Set matrix
	int** matrix = new int* [m + 1];
	for (int i = 0; i < m + 1; i++) {
		matrix[i] = new int[n + 1];
		for (int j = 0; j < n + 1; j++) {
			if (i == 0) 
				matrix[i][j] = j;
			else if (j == 0) 
				matrix[i][j] = i;
			else 
				matrix[i][j] = 0;
		}
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (X[i - 1] == Y[j - 1]) {
				matrix[i][j] = matrix[i - 1][j - 1];
			}
			else {
				matrix[i][j] = min({
					matrix[i][j - 1],
					matrix[i - 1][j],
					matrix[i - 1][j - 1]
					}) + 1;
			}
		}
	}
	cout << matrix[m][n] << '\n';	// Print result
	// Delete matrix;
	for (int i = 0; i < m; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}