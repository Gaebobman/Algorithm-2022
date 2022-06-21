// https://www.acmicpc.net/problem/1655
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue <int> leftq, rightq;	// ¦���϶� LEFT�� ���� Ȧ���϶� RIGHT�� ����
	int N, tmp, mid;	// N, tmp, ����� ��
	cin >> N;
	cin >> tmp;
	mid = tmp;
	cout << tmp << "\n";
	leftq.push(tmp);	// �ʱ⿡ �׻� ���ʿ� ���� ����
	for(int i = 0 ; i < N - 1; i++) {
		cin >> tmp;
		if (tmp > mid) {
			rightq.push(-tmp);
		}
		else {
			leftq.push(tmp);
		}
		if (leftq.size() - 2 == rightq.size()) {	// ���ʿ� ��
			rightq.push(-leftq.top());
			leftq.pop();
		}
		else if (rightq.size() - 1 == leftq.size()) {	// �����ʿ� ��
			leftq.push(-rightq.top());
			rightq.pop();
		
		}
		cout <<leftq.top() << "\n";
		mid = leftq.top();
	}
	return 0;
}
