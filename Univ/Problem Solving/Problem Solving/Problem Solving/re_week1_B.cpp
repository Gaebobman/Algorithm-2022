/* -- WA -- */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int result = 0;
		stack<char> mystack;
		mystack.push(-1);
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'C') {
				mystack.push(i);
			}
			else {
				if (!mystack.empty()) {
					mystack.pop();
				}
				if (!mystack.empty())
					result = max(result, i - mystack.top());
				if (mystack.empty()) {
					mystack.push(i);
				}
			}
		}
		// cout <<  "::: " << T << " ::::\n";
		cout << result << '\n';
	}
	return 0;
}