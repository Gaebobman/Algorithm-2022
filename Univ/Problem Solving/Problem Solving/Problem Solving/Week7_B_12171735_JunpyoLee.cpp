// CORRECT
#include <iostream>
#include <limits>
#include <vector>
#include <map>

using namespace std;

int main() {
 	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int result = 0;
		string S;
		vector<int> prefix_sum;
		multimap<int, int> m;
		cin >> S;
		multimap<int, int>::iterator it_up, it_low;
		prefix_sum.push_back(0);	// idx 0
		for (char c : S) {
			if (c == '0')
				prefix_sum.push_back(prefix_sum.back() - 1);
			else
				prefix_sum.push_back(prefix_sum.back() + 1);
		}
		m.insert({ 0, 0 });
		for (int i = 1; i <= S.size(); i++) {
			m.insert({ prefix_sum[i], i });
		}
		it_up = --m.end();
		while (1) {
			int tmp = it_up -> first;
			it_low = m.lower_bound(tmp);
			if (it_up == it_low) {
				if (it_up == m.begin())
					break;
			}
			else {
				result = max(result, it_up->second - it_low->second);
				if(it_low == m.begin())
					break;
			}
			it_up = --it_low;
		}
		cout << result << '\n';
	}
	return 0;
}