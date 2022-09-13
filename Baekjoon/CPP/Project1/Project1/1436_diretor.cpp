// https://www.acmicpc.net/problem/1436
#include <iostream>
using namespace std;


int main() {
	int N, cnt = 0;
	int current = 665;
	int tmp = 0;
	cin >> N;
	while (cnt != N) {
		current++;
		tmp = current;
		while (tmp != 0) 
		{
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			else {
				tmp /= 10;
			}		
		}
	}
	cout << current;
}