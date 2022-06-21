// https://www.acmicpc.net/problem/9375
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int M, N, result;
	cin >> M;
	string name, type;
	while (M--) {
		map<string, int> type_count;
		result = 1;
		cin >> N;
		while (N--) {
			cin >> name >> type;
			if (type_count.find(type) == type_count.end()) {
				type_count[type] = 1;
			}
			else {
				type_count[type]++;
			}
		}

		for (auto i : type_count) {
			result = result * (i.second + 1);
		}
		
		cout << result - 1 << "\n";
	}
	return 0;
}