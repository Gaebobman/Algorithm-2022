#include <iostream>
#include <vector>
#include <math.h>
const int ERR = -10000;
using namespace std;

int gcd(int first, int second) {
	if (first < second) {
		int tmp = first;
		first = second;
		second = tmp;
	}
	int remain = second;
	while (1) {
		remain = first % second;
		if (remain == 0) {
			return second;
		}
		if (remain == 1) {
			return -10000;
		}
		first = second;
		second = remain;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, n, m;
	cin >> T;
	while (T--) {
		vector <int> a, b;
		int tmp;
		int SOF1 = -1;
		int SOF2 = -1;
		// 병사의 수 입력
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			a.push_back(tmp);
		}
		for (int i = 0; i < m; i++) {
			cin >> tmp;
			b.push_back(tmp);
		}
		// 용병의 능력치를 저장
		// INHA에서 고용할 용병의 능력치 계산
		for (int i = 0; i < m - 1; i++) {
			if (SOF1 != -1) {
				SOF1 = gcd(SOF1, b[i + 1]);
				continue;
			}
			SOF1 = gcd(b[i], b[i + 1]);
			if (SOF1 == ERR) {
				SOF1 = -1;
				break;
			}
		}

		for (int i = 0; i < n - 1; i++) {
			// cout << i << " : " << i + 1 << endl;
			if (SOF2 != -1) {
				SOF2 = gcd(SOF2, a[i + 1]);
				continue;
			}
			SOF2 = gcd(a[i], a[i + 1]);
			if (SOF2 == ERR) {
				SOF2 = -1;
				break;
			}
		}
		// cout << " SOF1: " << SOF1 << " SOF2: " << SOF2 << endl;
		// 자신들의 병사를 잡는지 확인
		if (SOF1 != -1) {

			for (int i = 0; i < n; i++) {
				if (gcd(SOF1, a[i]) == SOF1) {
					SOF1 = -1;
				}
			}
		}

		if (SOF2 != -1) {
			for (int i = 0; i < m; i++) {
				if (gcd(SOF2, b[i]) == SOF2) {
					SOF2 = -1;
				}
			}
		}
		if (a.size() == 1)
			SOF2 = a[0];
		if (b.size() == 1)
			SOF1 = b[0];

		if (SOF1 == SOF2) {
			SOF1 = -1;
			SOF2 = -1;
		}

		cout << SOF1 << ' ' << SOF2 << "\n";
		a.clear();
		b.clear();
	}
	return 0;
}