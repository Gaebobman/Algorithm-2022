#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		stack<int> my_stack;
		int result = 0;
		my_stack.push(-1);
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == 'C') {
				my_stack.push(i);
			}
			else{
				if (!my_stack.empty()) {
					my_stack.pop();
				}
				if (!my_stack.empty()) {
					result = max(result, i - my_stack.top());
				}
				if (my_stack.empty()) {
					my_stack.push(i);
				}
			}
		}
		cout << result << '\n';
	}
	return 0;
}