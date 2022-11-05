#include <iostream>
#include <vector>

using namespace std;

int calc_room(vector<pair<int, int>>& shark, vector<int>& room, int N, int M);
bool is_okay(pair<int, int>& shark, int room);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		int a, b;
		vector<pair<int, int>> shark;
		vector<int> room;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			shark.push_back({ a, b });
		}
		for (int i = 0; i < M; i++) {
			cin >> a;
			room.push_back(a);
		}
	}

	return 0;
}

int calc_room(vector<pair<int, int>>& shark, vector<int>& room, int N, int M) {
	int** D = new int* [M]; // D[M][N]
	for (int j = 0; j < M; j++) {
		int* tmp = new int[N];
		D[j] = tmp;
		for (int i = 0; i < N; i++) {
			D[j][i] = 0;
		}
	}
	// init
	for (int j = 0; j < M; j++) {
		if (is_okay(shark[0], room[j]))
			D[j][0] = 1;
	}
	for (int i = 0; i < N; i++) {
		if (is_okay(shark[i], room[0]))
			D[0][i] = 1;
	}
	// calc

	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {

		}
	}


	for (int i = 0; i < N; i++) {
		delete[] D[i];
	}
	delete[] D;
}

bool is_okay(pair<int, int>& shark, int room) {
	if (shark.first <= room && room <= shark.second)
		return true;
	else
		false;
}