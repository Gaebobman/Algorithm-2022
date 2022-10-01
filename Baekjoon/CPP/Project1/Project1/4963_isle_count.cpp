// https://www.acmicpc.net/problem/4963
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int w = 1, h = 1;
	string input = "";

	while (w != 0 && h != 0) {
		vector<string> map;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> input;
			input.erase(remove(input.begin(), input.end(), ' '), input.end());
			map.push_back(input);
		}

	}



}