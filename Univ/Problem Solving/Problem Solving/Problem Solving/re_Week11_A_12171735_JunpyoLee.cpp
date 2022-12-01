// CORRECT
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
	ll N;
	cin >> T;
	vector<pair<ll, ll>> beta;
	vector<ll> alpha;
	beta.push_back({ 0, 0 });
	beta.push_back({ 0, 1 });
	alpha.push_back(0);
	alpha.push_back(1);
	for (int i = 2; i <= 29; i++) {
		pair<ll, ll> temp = beta.back();
		ll temp_first = temp.first + temp.second;
		ll temp_second = temp_first + pow(2, i - 1);
		beta.push_back({ temp_first, temp_second });
		ll temp_alpha = alpha.back() + beta[i].first + beta[i].second;
		alpha.push_back(temp_alpha);
	}
	while (T--) {
		int K = 0, tmp = 0;
		cin >> N;
		while (N != tmp) {
			K++;
			tmp = pow(2, K);
		}
		cout << alpha[K - 1] + K <<' '<< alpha[K - 1] + N << '\n';
	}
	return 0;
}

/*
(1의 갯수) || (0의 갯수)								이전갯수 + (이전갯수 + 증가된 수의 개수)

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