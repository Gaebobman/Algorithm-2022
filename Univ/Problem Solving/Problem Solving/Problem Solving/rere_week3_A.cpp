#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool alram(const int n, const int d, vector<int> &cal, int count[], int start_day) {
	int current = 0;
	if (d % 2 == 0) {
		int first = -1;
		for (int i = 1; i < 201; i++) {
			current += count[i];
			if (first == -1 && current >= d / 2) {
				first = i;
			}

			if (current > d / 2) {
				if (first + i <= cal[start_day + d]) {
					count[cal[start_day]]--;
					count[cal[start_day+ d]]++;
					return true;
				}
				else {
					count[cal[start_day]]--;
					count[cal[start_day + d]]++;
					return false;
				}
			}
		}
	}
	else {
		for (int i = 1; i < 201; i++) {
			current += count[i];
			if (current > d / 2) {
				if (i * 2 <= cal[start_day + d]) {
					count[cal[start_day]]--;
					count[cal[start_day + d]]++;
					return true;
				}
				else {
					count[cal[start_day]]--;
					count[cal[start_day + d]]++;
					return false;
				}
			}
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int n, d, tmp;
		vector<int> cal;
		cin >> n >> d;
		int* count = new int[201];
		int alram_cnt = 0;
		memset(count, 0, (201) * sizeof(int));
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			cal.push_back(tmp);
		}
		// 초기작업
		for (int i = 0; i < d; i++) {
			count[cal[i]]++;
		}
		for (int i = 0; i < n - d; i++) {
			if (alram(n, d, cal, count, i)) {
				alram_cnt++;
			}
		}
		cout << alram_cnt << '\n';

		delete[] count;
	}

	return 0;
}