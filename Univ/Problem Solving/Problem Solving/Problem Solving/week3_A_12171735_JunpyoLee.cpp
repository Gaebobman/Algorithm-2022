#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int T, n = 0, d = 0, tmp = 0, med = 0;
	vector<int> calorie;
	cin >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			calorie.push_back(tmp);
		}
		vector<int> meds;

		for (int i = 2; i < n; i++) {

		}
		

	}
	
	return 0;
}