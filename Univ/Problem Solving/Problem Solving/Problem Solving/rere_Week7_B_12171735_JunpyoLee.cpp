#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string S;
		vector<int> pre_sum;
		multimap<int, int> my_map;
		multimap<int, int>::iterator it_up, it_low;
		int result = 0;
		cin >> S;
		pre_sum.push_back(0);
		for (char c : S) {
			if (c == '0')
				pre_sum.push_back(pre_sum.back() - 1);
			else
				pre_sum.push_back(pre_sum.back() + 1);
		}
		my_map.insert({ 0, 0 });
		for (int i = 1; i < S.length(); i++) {
			my_map.insert({ pre_sum[i], i });
		}
		it_up = --my_map.end();
		while (1) {
			int tmp = it_up->first;
			it_low = my_map.lower_bound(tmp);
			if (it_low == it_up) {
				if (it_up == my_map.begin())
					break;
			}
			else {
				result = max(result, it_up->second - it_low->second);
				if (it_low == my_map.begin())
					break;
			}
			it_up = --it_low;
		}
		cout << result << '\n';
	}
	return 0;
}