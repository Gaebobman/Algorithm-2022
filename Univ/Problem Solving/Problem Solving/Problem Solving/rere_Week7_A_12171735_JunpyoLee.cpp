#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		stack<int> st;
		int tmp = 0;
		for (char c : S) {
			if (c == '+') {
				tmp = st.top(); st.pop();
				tmp += st.top(); st.pop();
				st.push(tmp);
			}
			else if (c == '*') {
				tmp = st.top(); st.pop();
				tmp *= st.top(); st.pop();
				st.push(tmp);
			}
			else if (c == '-') {
				tmp = -st.top(); st.pop();
				tmp += st.top(); st.pop();
				st.push(tmp);
			}
			else {
				st.push(c - '0');
			}
		}
		cout << st.top() << '\n';
	}
	return 0;
}