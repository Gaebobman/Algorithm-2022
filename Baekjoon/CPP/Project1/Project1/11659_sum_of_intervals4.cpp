// https://www.acmicpc.net/problem/11659
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, i, j, tmp;
	vector<int> arr;
	cin >> N >> M;
	for (int k = 0; k < N; k++) {
		cin >> tmp;
		if (k == 0) {
			arr.push_back(tmp);
		}
		else {
			tmp += arr.back();
			arr.push_back(tmp);
		}
	}
	while (M--) {
		cin >> i >> j;
		if (i == 1) {
			if (j == 1) {
				cout << arr[0] << endl;
				continue;
			}
			else {
				cout << arr[j - 1]<<endl;\
				continue;
			}
		}
		else if(i == j){
			cout << arr[j- 1] - arr[i - 2] << endl;
		}
		else {
			cout << arr[j - 1] - arr[i - 2] << endl;
		}
		
	}
	return 0;
}