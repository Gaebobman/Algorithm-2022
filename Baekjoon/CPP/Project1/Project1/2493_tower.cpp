// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	stack<pair<int, int>> towers;	// <자신의 높이, 인덱스>
	vector<int> result;
	int N, tmp;
	cin >> N;
	cin >> tmp;
	towers.push(make_pair(tmp, 1));
	result.push_back(0);
	for (int i = 2; i <= N; i++) {
		cin >> tmp;
		if (towers.top().first > tmp) {			// 만일 스택의 top이 지금 들어온것보다 높다면
			result.push_back(towers.top().second);	//	결과에 지금 top의 인덱스를 넣고
			towers.push(make_pair(tmp, i));			// 스택에 tmp와 인덱스 정보를 넣음
		}
		else {
			while (towers.top().first < tmp) {
				towers.pop();
				if (towers.empty()) {
					result.push_back(0);
					towers.push(make_pair(tmp, i));	// 모두 pop 한 경우
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