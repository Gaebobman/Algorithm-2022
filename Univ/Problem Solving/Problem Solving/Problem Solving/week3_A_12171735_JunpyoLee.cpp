#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool alram(int radix[], vector<int>& calorie, const int d, const int start_day) {
	int median_count = 0;
	int first = -1;
	// 짝수인 경우
	if (d % 2 == 0) {
		for (int i = 0; i < 201; i++) {
			if (radix[i] != 0) {
				median_count += radix[i];
			}
			if (first == -1 && median_count >= d / 2) {
				first = i;
			}
			if (median_count >= d / 2 + 1) {
				if (first + i <= calorie[start_day + d]) {
					// radix 변경해주고, true 반환
					radix[calorie[start_day]]--;
					radix[calorie[start_day + d]]++;
					//cout << "경고!: " << calorie[start_day + d] << endl;
					return true;
				}
				else {
					radix[calorie[start_day]]--;
					radix[calorie[start_day + d]]++;
					return false;
				}
			}
		}
	}else{
		for (int i = 0; i < 201; i++) {
			if (radix[i] != 0) {
				median_count += radix[i];
				// 중앙값의 인덱스를 찾으면
				if (median_count > d / 2){
					// 중앙값은 i 임.
					// 타겟한 날이 중앙값의 두 배 한 것보다 크면
					if (i * 2 <= calorie[start_day + d]) {
						// radix 변경해주고, true 반환
						radix[calorie[start_day]]--;
						radix[calorie[start_day + d]]++;
						//cout << "경고!: " << calorie[start_day + d] << endl;
						return true;
					}
					else {
						radix[calorie[start_day]]--;
						radix[calorie[start_day + d]]++;
						return false;
					}
				}
			}
		}
	}


	return true;
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int T, n = 0, d = 0, tmp = 0;
	
	cin >> T;
	while (T--) {
		int radix[201] = { 0 };
		vector<int> calorie;
		int alram_count = 0;
		cin >> n >> d;

		for (int i = 0; i < n; i++) {
			cin >> tmp;
			calorie.push_back(tmp);
		}
		// radix 초기 설정; 칼로리 0일 부터 d - 1 일까지
		for (int i = 0; i < d; i++) {
			radix[calorie[i]]++;
		}
		for (int i = 0; i < n - d; i++) {
			if (alram(radix, calorie, d, i)) {
				alram_count++;
			}
		}
		cout << alram_count << '\n';
	}
	
	
	return 0;
}