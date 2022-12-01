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
		string expr;
		stack<int> num;
		int result = 0;
		cin >> expr;
		for (char i = 0; i < expr.length(); i++) {
			if (expr[i] == '*') {
				result = num.top(); num.pop();
				result *= num.top(); num.pop();
				num.push(result);
			}
			else if (expr[i] == '+') {
				result = num.top(); num.pop();
				result += num.top(); num.pop();
				num.push(result);
			}
			else if(expr[i] == '-') {
				result = -num.top(); num.pop();
				result += num.top(); num.pop();
				num.push(result);
			}
			else {
				num.push(expr[i] - 48);
			}
		}
		cout << num.top() << '\n';
	}
	return 0;
}