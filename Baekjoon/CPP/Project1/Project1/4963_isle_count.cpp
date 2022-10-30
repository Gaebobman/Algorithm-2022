// https://www.acmicpc.net/problem/4963
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 1  2  3   4   5   6   7   8
// 00 45 90 135 180 225 270 315
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int M[50][50];
int visited[50][50];

void bfs(int w, int h, int x, int y);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int w = 1, h = 1;
	int tmp = 0;

	while (w != 0 && h != 0) {
		int result = 0;
		cin >> w >> h;
		// ���� �Է�
		for (int j = 0; j < h; j++) {
			for (int i = 0; i < w; i++) {
				cin >> tmp;
				M[i][j] = tmp;
			}
		}
		// �湮���� �ʱ�ȭ
		for (int j = 0; j < h; j++) {
			for (int i = 0; i < w; i++) {
				visited[i][j] = 0;
			}
		}
		// ���� Ȯ���ϸ� �� bfs
		for (int j = 0; j < h; j++) {
			for (int i = 0; i < w; i++) {
				if (M[i][j] == 1 && visited[i][j] == 0) {
					bfs(w, h, i, j);
					result++;
				}
			}
		}
		if(w != 0 && h != 0)
			cout << result << '\n';
	}
	return 0;
}

void bfs(int w, int h, int x, int y) {
	queue<pair<int, int>> Q;
	Q.push({ x, y });
	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();
		for (int j = 0; j < 8; j++) {
			for (int i = 0; i < 8; i++) {
				int tx = x + dx[i];
				int ty = y + dy[j];
				
				// ���ǿ� �´���?
				if (tx >= 0 && tx < w && ty >= 0 && ty < h) {
					if (visited[tx][ty] == 0 && M[tx][ty] == 1) {
						visited[tx][ty] = 1;
						Q.push({ tx,ty });
					}
				}
			}
		}
	}
}