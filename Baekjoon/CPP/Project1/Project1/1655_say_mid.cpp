// https://www.acmicpc.net/problem/1655
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue <int> leftq, rightq;	// 짝수일때 LEFT에 저장 홀수일때 RIGHT에 저장
	int N, tmp, mid;	// N, tmp, 가운데의 값
	cin >> N;
	cin >> tmp;
	mid = tmp;
	cout << tmp << "\n";
	leftq.push(tmp);	// 초기에 항상 왼쪽에 놓고 시작
	for(int i = 0 ; i < N - 1; i++) {
		cin >> tmp;
		if (tmp > mid) {
			rightq.push(-tmp);
		}
		else {
			leftq.push(tmp);
		}
		if (leftq.size() - 2 == rightq.size()) {	// 왼쪽에 쏠림
			rightq.push(-leftq.top());
			leftq.pop();
		}
		else if (rightq.size() - 1 == leftq.size()) {	// 오른쪽에 쏠림
			leftq.push(-rightq.top());
			rightq.pop();
		
		}
		cout <<leftq.top() << "\n";
		mid = leftq.top();
	}
	return 0;
}
