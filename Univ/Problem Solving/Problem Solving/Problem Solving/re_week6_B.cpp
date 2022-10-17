#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

typedef struct {
	int number;
	int size;
} disk;

int K, moves = 0;
stack<disk> c1, c2, c3;
void move(int n, int from, int to) {
	int size_of_disk = 0;
	if (moves < K) {
		disk a;
		if (from == 1) {
			a = c1.top(); c1.pop();
			size_of_disk = a.size;
		}
		else if (from == 2) {
			a = c2.top(); c2.pop();
			size_of_disk = a.size;
			int move_left = K - moves;
			// 2에서 뽑을 것이 이동수를 초과할 시
			if (move_left < size_of_disk) {
				disk tmp{ a.number,size_of_disk - move_left };
				c2.push(tmp);
				a = disk{ a.number, move_left };
				size_of_disk = move_left;
			}

		}
		else {
			a = c3.top(); c3.pop();
			size_of_disk = a.size;
		}

		if (to == 1) {
			c1.push(a);
		}
		else if (to == 2) {
			int move_left = K - moves;
			// 2로 들어갈 것이 이동수를 초과할 시
			if (move_left < size_of_disk) {
				disk tmp{ a.number,move_left };
				c2.push(tmp);
			}
			else {
				c2.push(a);
			}
			
		}
		else {
			c3.push(a);
		}
	}
	moves += size_of_disk;
}

void hanoi(int n, int from, int to, int aux) {
	if (n == 1) {
		move(1, from, to);
	}
	else {
		hanoi(n - 1, from, aux, to);
		move(n, from, to);
		hanoi(n - 1, aux, to, from);
	}
}

void init_test(int disk_count[], int N) {
	while (!c1.empty()) c1.pop();
	while (!c2.empty()) c2.pop();
	while (!c3.empty()) c3.pop();
	for (int i = N; i > 0; i--) {
		if (disk_count[i] != 0) 
			c1.push(disk{ i, disk_count[i] });
	}
	moves = 0;
}

void print_disk(disk a) {
	for (int i = 0; i < a.size; i++) {
		cout << a.number << ' ';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int N, m;
		cin >> N;
		int* disk_count = new int[N + 1];
		memset(disk_count, 0, (N + 1) * sizeof(int));

		for (int i = 1; i <= N; i++) {
			cin >> m;
			disk_count[i] = m;
		}
		
		cin >> K;
		init_test(disk_count, N);
		hanoi(N, 1, 3, 2);
		if (c2.empty()) {
			cout << 0;
		}
		else {
			while (!c2.empty()) {
				print_disk(c2.top());
				c2.pop();
			}
		}
		cout << '\n';
		delete[] disk_count;
	}
	return 0;
}