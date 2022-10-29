#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s1, s2;
		bool result = true;
		int alp[26] = { 0 };
		cin >> s1 >> s2;
		for (int i = 0; i < s1.size(); i++) {
			alp[s1[i] - 'A'] = 1;
		}
		for (int i = 0; i < s2.size(); i++) {
			if (alp[s2[i] - 'A'] >= 1) {
				alp[s2[i] - 'A']++;
			}
			else {
				result = false;
				break;
			}
		}
		if (result) {
			for (int i = 0; i < 26; i++) {
				if (alp[i] == 1) {
					result = false;
					break;
				}
			}
		}
		if (result) 
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}