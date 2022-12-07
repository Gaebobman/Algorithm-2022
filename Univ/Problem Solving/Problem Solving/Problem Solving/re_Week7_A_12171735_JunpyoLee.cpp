// CORRECT
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
		int result = 0;
		stack<int> my_stack;
		for (char c : S) {
			if (c == '+') {
				result = my_stack.top(); my_stack.pop();
				result += my_stack.top(); my_stack.pop();
				my_stack.push(result);
			}
			else if (c == '*') {
				result = my_stack.top(); my_stack.pop();
				result *= my_stack.top(); my_stack.pop();
				my_stack.push(result);
			}
			else if (c == '-') {
				result = -my_stack.top(); my_stack.pop();
				result += my_stack.top(); my_stack.pop();
				my_stack.push(result);
			}
			else {
				my_stack.push(c - 48);
			}
		}
		cout << my_stack.top() << '\n';
	}
	return 0;
}