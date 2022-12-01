#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct shark {
	int key;
	int low;
	int high;
};

struct compare {
	bool operator()(const shark& a, const shark& b) {
		return a.high < b.high;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, A, B, C;
		vector<shark> temp;
		vector<int> tank;
		priority_queue<shark, compare> q;
		cin >> N >> M;
		for (int i = 0; i < N; i++ ) {
			cin >> A >> B;
			shark tmp = { i, A, B };
			temp.push_back(tmp);
		}
	}
	return 0;
}