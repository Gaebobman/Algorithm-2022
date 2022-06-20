// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	stack<pair<int, int>> towers;	// <�ڽ��� ����, �ε���>
	vector<int> result;
	int N, tmp;
	cin >> N;
	cin >> tmp;
	towers.push(make_pair(tmp, 1));
	result.push_back(0);
	for (int i = 2; i <= N; i++) {
		cin >> tmp;
		if (towers.top().first > tmp) {			// ���� ������ top�� ���� ���°ͺ��� ���ٸ�
			result.push_back(towers.top().second);	//	����� ���� top�� �ε����� �ְ�
			towers.push(make_pair(tmp, i));			// ���ÿ� tmp�� �ε��� ������ ����
		}
		else {
			while (towers.top().first < tmp) {
				towers.pop();
				if (towers.empty()) {
					result.push_back(0);
					towers.push(make_pair(tmp, i));	// ��� pop �� ���
					break;
				}
			}
			if (towers.top().first > tmp) {
				result.push_back(towers.top().second);
				towers.push(make_pair(tmp, i));
			}

		}
	}


	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
	return 0;
}