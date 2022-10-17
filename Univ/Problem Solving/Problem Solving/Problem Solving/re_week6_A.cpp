#include <iostream>
#include <stack>

using namespace std;

int K, moves = 0;
stack<int> c1, c2, c3;
void move(int n, int from, int to) {
	if (moves < K) {
		int a;
		if (from == 1) {
			a = c1.top(); c1.pop();
		}
		else if (from == 2) {
			a = c2.top(); c2.pop();
		}
		else {
			a = c3.top(); c3.pop();
		}

		if (to == 1) {
			c1.push(a);
		}
		else if (to == 2) {
			c2.push(a);
		}
		else {
			c3.push(a);
		}
	}
	moves++;
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
void init_test(int n) {
	while (!c1.empty()) c1.pop();
	while (!c2.empty()) c2.pop();
	while (!c3.empty()) c3.pop();
	moves = 0;
	for (int i = n; i >= 1; i--)
		c1.push(i);
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N >> K;
		init_test(N);
		hanoi(N, 1, 3, 2);
		if (c2.empty()) {
			cout << 0;
		}
		else {
			while (!c2.empty()) {
				cout << c2.top() << ' ';
				c2.pop();
			}
		}
		cout << '\n';
	}
	return 0;
}