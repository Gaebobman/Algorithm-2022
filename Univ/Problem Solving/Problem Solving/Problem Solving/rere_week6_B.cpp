#include <iostream>
#include <stack>
#include <cstring>
#include <stack>

using namespace std;
typedef struct {
	int number;
	int size;

} disk;

stack<disk> s1, s2, s3;
int K, moves = 0;

void move(int n, const int from, const int to) {
	int size_of_disk = 0;
	if (moves < K) {
		disk a;
		if (from == 1) {
			a = s1.top(); s1.pop();
			size_of_disk = a.size;
		}
		else if (from == 2) {
			a = s2.top(); s2.pop();
			size_of_disk = a.size;
			int move_left = K - moves;
			if (move_left < size_of_disk) {
				disk tmp{ a.number, size_of_disk - move_left };
				s2.push(tmp);
				a = disk{ a.number, move_left };
				size_of_disk = move_left;
			}
		}
		else {
			a = s3.top(); s3.pop();
			size_of_disk = a.size;
		}

		if (to == 1) {
			s1.push(a);
		}
		else if (to == 2) {
			int move_left = K - moves;
			if (move_left < size_of_disk) {
				disk tmp{ a.number, move_left };
				s2.push(tmp);
			}
			else {
				s2.push(a);
			}
		}
		else {
			s3.push(a);
		}
	}
	moves += size_of_disk;
}


void hanoi(int n, const int from, const int to, const int aux) {
	if (n == 1) {
		move(1, from, to);
	}
	else {
		hanoi(n - 1, from, aux, to);
		move(n, from, to);
		hanoi(n - 1, aux, to, from);
	}
}

void init() {
	while (!s1.empty()) s1.pop();
	while (!s3.empty()) s3.pop();
	moves = 0;
}

void print_disk() {
	if (s2.empty()) {
		cout << 0;
	}
	else {
		while (!s2.empty()) {
			disk a = s2.top(); s2.pop();
			for (int i = 0; i < a.size; i++) {
				cout << a.number << ' ';
			}
		}
	}
	cout << '\n';
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		int* count = new int[N + 1];
		memset(count, 0, (N + 1) * sizeof(int));

		for (int i = 1; i <= N; i++) {
			cin >> M;
			count[i] = M;
		}

		cin >> K;
		for (int i = N; i >= 1; i--) {
			if(count[i] != 0)
				s1.push(disk{ i, count[i] });
		}
		hanoi(N, 1, 3, 2);
		print_disk();
		init();
		delete[] count;
	}

	return 0;
}