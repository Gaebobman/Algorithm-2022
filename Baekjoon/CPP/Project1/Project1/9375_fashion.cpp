// https://www.acmicpc.net/problem/9375
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int M, N, result;
	cin >> M;
	string name, type;
	while (M--) {
		cin >> N;

		vector<pair<string, int>> type_count;

		while (N--) {
			cin >> name >> type;
			if (find(type_count.begin(), type_count.end(), type) != type_count.end()) {
				type_count[find(type_count.begin(), type_count.end(), type) - type_count.begin()].second++;
			}
			else {
				type_count.push_back(make_pair(type, 0));
			}
		}
		
	}
	return 0;
}