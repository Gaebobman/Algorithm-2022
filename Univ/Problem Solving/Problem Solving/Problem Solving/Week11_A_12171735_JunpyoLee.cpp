#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	vector<pair<ll, ll>> beta;
	vector<ll> alpha;
	beta.push_back({ 0, 0 });
	beta.push_back({ 0, 1 });
	alpha.push_back(0);
	alpha.push_back(1);
	for (int i = 2; i <= 29; i++) {
		pair <ll, ll> tmp = beta.back();
		ll tmp_first = tmp.first + tmp.second;
		ll tmp_second = tmp_first + pow(2, i - 1);
		beta.push_back({ tmp_first, tmp_second });
		
	}
	for (int i = 2; i <= 29; i++) {
		ll tmp = alpha.back() + beta[i].first + beta[i].second;
		alpha.push_back(tmp);
	}

	cin >> T;
	while (T--) {
		int N;
		int K = 0;
		cin >> N;
		ll tmp = 0;
		while (tmp != N) {
			K++;
			tmp = pow(2, K);
		}
		//cout << "K: " << K << endl;

		cout << alpha[K - 1] + K  << ' '<< N + alpha[K - 1] << '\n';
	}
	
	return 0;
}

/*
(1의 갯수) || (0의 갯수)

1~1: 1  	(i =0)													0 + 0     ||	0 + 0

2~3: 10, 11  (i =1)												0 + (0 + 1)   ||    0 + 1

4~7: 100, 101, 110, 111	(i = 2)	 								1 + (1 + 2)   ||	(1 + 2)+ 1

8~15: 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111			4 + (4 + 4)   ||	(4 + 4) + 4

16:~31: 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111	 12 + (12+ 8) ||	(12 + 8) + 12
		  11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111



==> 마지막의 1의 갯수를 N 만큼 더함, 0의 갯수를 K만큼 더함
결론:
1의 갯수 = N + ALPHA [K -1]	(단, 주어진 수는 4 이상)
0의 갯수 = ALPHA 			(단, 주어진 수는 4 이상)
*/