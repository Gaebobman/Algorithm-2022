#include <iostream>
#include <vector>

using namespace std;
int alram(const int d, const int start, int count[], vector<int>& cal) {
	int median_count = 0;
	int first = -1;		// d 가 짝수일 경우 중위값을 계산하기 위함
						// ==> first + i 가 중위값의 2배임
	if (d % 2 == 0) {
		for (int i = 0; i < 201; i++) {
			if (count[i] != 0) {
				median_count += count[i];
			}
			// 중위값을 계산하기 위한 첫번째 값 (first + x);
			if (first == -1 && median_count >= d / 2) {
				first = i;
			}
			// 중위값을 계산하기 위한 두번째 값
			if (median_count >= d / 2 + 1) {
				if (first + i <= cal[start + d]) {
					// 그 후 다음 계산을 위해 Count 배열을 작업해줌
					count[cal[start]]--;
					count[cal[start + d]]++;
					return 1;
				}
				else {
					// 그 후 다음 계산을 위해 Count 배열을 작업해줌
					count[cal[start]]--;
					count[cal[start + d]]++;
					return 0;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 201; i++) {
			if (count[i] != 0) {
				median_count += count[i];
			}
			if (median_count > d / 2) {
				if (i * 2 <= cal[start + d]) {
					count[cal[start]]--;
					count[cal[start + d]]++;
					return 1;
				}
				else {
					count[cal[start]]--;
					count[cal[start + d]]++;
					return 0;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, n, d, tmp;
	cin >> T;
	while (T--) {
		vector<int> cal;
		int count[201] = { 0 };
		int alram_count = 0;
		cin >> n >> d;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			cal.push_back(tmp);
		}
		for (int i = 0; i < d; i++) {
			count[cal[i]]++;
		}
		for (int i = 0; i < n - d; i++) {
			alram_count += alram(d, i, count, cal);
		}
		cout << alram_count << '\n';
	}
	return 0;
}