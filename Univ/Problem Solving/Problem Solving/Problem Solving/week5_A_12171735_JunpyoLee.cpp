#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	string a, b;
	cin >> T;
	while (T--) {
		bool flag = true;
		vector<int> alp(26);
		vector<int> alp_cnt(26);
		cin >> a >> b;
		for (int i = 0; i < a.length(); i++) {
			alp[(int)a[i] - 65] = 1;
			alp_cnt[(int)a[i] - 65]++;
		}
		for (int i = 0; i < b.length(); i++) {
			if (alp[(int)b[i] - 65] == 0) {
				flag = false;
				break;
			}
			else {
				alp_cnt[(int)b[i] - 65]--;
			}
		}
		if (flag == true) {
			for (int i = 0; i < 26; i++) {
				if (alp_cnt[i] >= 1) {
					flag = false;
				}
			}
		}

		if (flag == false) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}

	}
	return 0;
}