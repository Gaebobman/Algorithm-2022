#include <iostream>
#include <string>
#include <queue>

using namespace std;

// 00 90 180 270
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int visited[100][100];
vector<string> M;	// Map

void bfs(int N, int x, int y, char color);
void bfs_col(int N, int x, int y, char color);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int result1 = 0, result2 = 0;
	string tmp;
	cin >> N;
	// ¸Ê ÀÔ·Â
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		M.push_back(tmp);
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			visited[i][j] = 0;
		}
	}

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (visited[i][j] == 0) {
				result1++;
				bfs(N, i, j, M[i][j]);
			}
		}
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			visited[i][j] = 0;
		}
	}

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (visited[i][j] == 0) {
				result2++;
				bfs_col(N, i, j, M[i][j]);
			}
		}
	}

	cout << result1 << ' ' << result2 << '\n';

	return 0;
}


// »ö¾à¾Æ´Ô
void bfs(int N, int x, int y, char color) {
	queue<pair<int, int>> Q; // {xÁÂÇ¥, yÁÂÇ¥}
	Q.push({ x, y });
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int tx = x + dx[i];
				int ty = y + dy[j];
				if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
					if (M[tx][ty] == color && visited[tx][ty] == 0) {
						visited[tx][ty] = 1;
						Q.push({ tx, ty });
					}
				}
			}
		}
	}
}

// »ö¾à
void bfs_col(int N, int x, int y, char color) {
	queue<pair<int, int>> Q; // {xÁÂÇ¥, yÁÂÇ¥}
	Q.push({ x, y });
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int tx = x + dx[i];
				int ty = y + dy[j];
				if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
					if (color == 'R' || color == 'G') {
						if ((M[tx][ty] == 'R' || M[tx][ty] == 'G') && visited[tx][ty] == 0) {
							Q.push({ tx, ty });
							visited[tx][ty] = 1;
						}
					}
					else {
						if (M[tx][ty] == color && visited[tx][ty] == 0) {
							Q.push({ tx, ty });
							visited[tx][ty] = 1;
						}
					}
				}
			}
		}
	}
}

/*
3
RGB
RRR
RRR
*/