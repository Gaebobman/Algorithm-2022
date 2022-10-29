#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int K, moves = 0;
stack<int> s1, s2, s3;
void move(int n, const int from, const int to) {
	int a = 0;
	if (moves < K) {
		if (from == 1) {
			a = s1.top(); s1.pop();
		}
		else if (from == 2) {
			a = s2.top(); s2.pop();
		}
		else {
			a = s3.top(); s3.pop();
		}

		if (to == 1) {
			s1.push(a);
		}
		else if (to == 2) {
			s2.push(a);
		}
		else {
			s3.push(a);
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
void print_and_init() {
	if (s2.empty()) {
		cout << 0 << '\n';
	}
	else {
		while (!s2.empty()) {
			cout << s2.top() << ' '; s2.pop();
		}
		cout << '\n';
	}
	while (!s1.empty()) s1.pop();
	while (!s3.empty()) s3.pop();
	moves = 0;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N >> K;
		for (int i = N; i >= 1; i--) {
			s1.push(i);
		}
		hanoi(N, 1, 3, 2);
		print_and_init();
	}
	return 0;
}