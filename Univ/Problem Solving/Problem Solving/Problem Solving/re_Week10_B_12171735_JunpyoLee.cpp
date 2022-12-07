#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, A, B, C;
		vector<pair<int, int>> shark;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			shark.push_back({ A, B });
		}
	}
	return 0;
}