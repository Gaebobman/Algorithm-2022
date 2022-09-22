#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool alram(int radix[], vector<int>& calorie, const int d, const int start_day) {
	int median_count = 0;
	int first = -1;
	// ¦���� ���
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
					// radix �������ְ�, true ��ȯ
					radix[calorie[start_day]]--;
					radix[calorie[start_day + d]]++;
					//cout << "���!: " << calorie[start_day + d] << endl;
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
				// �߾Ӱ��� �ε����� ã����
				if (median_count > d / 2){
					// �߾Ӱ��� i ��.
					// Ÿ���� ���� �߾Ӱ��� �� �� �� �ͺ��� ũ��
					if (i * 2 <= calorie[start_day + d]) {
						// radix �������ְ�, true ��ȯ
						radix[calorie[start_day]]--;
						radix[calorie[start_day + d]]++;
						//cout << "���!: " << calorie[start_day + d] << endl;
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
		// radix �ʱ� ����; Į�θ� 0�� ���� d - 1 �ϱ���
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