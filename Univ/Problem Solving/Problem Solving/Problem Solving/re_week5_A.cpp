#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		string plain, cipher;
		cin >> plain >> cipher;
		int alp[26] = { 0 };
		bool result = true;

		for (int i = 0; i < plain.length(); i++) {
			alp[plain[i] - 'A']++;
		}
		for (int i = 0; i < cipher.length(); i++) {
			if (alp[cipher[i] - 'A']  < 1) {
				result = false;
				break;
			}
			else {
				alp[cipher[i] - 'A']++;
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