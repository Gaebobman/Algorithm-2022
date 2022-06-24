// https://www.acmicpc.net/problem/1715
#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue <int, vector<int>, greater<int>> myqueue;		// ī�� ������ ����� ť(min heap)�� ���� 
	int N, tmp, result;		// input ������, �Է��� ���� �ӽú���
	result = 0;
	cin >> N;
	while (N--) {
		cin >> tmp;
		myqueue.push(tmp);
	}
	while (myqueue.size() > 1) {
		tmp = myqueue.top();	// ���� queue���� ����(ī�� ��) �ϳ��� ���� (�� �������� �ּ���)
		myqueue.pop();
		tmp += myqueue.top();	// queue���� ����(ī�嵦)�� �� �̾Ƽ� �� ���� ��ħ 
		myqueue.pop();
		myqueue.push(tmp);	// �׸��� queue�� ������ ( ������ ���� ���� �߰��Ȱ� �� ����)
		result += tmp;
	}
	cout << result;
	return 0;
}