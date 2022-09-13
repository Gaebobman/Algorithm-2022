// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>
using namespace std;

bool check_availablity(int cur, int prev, bool* queens, int n_size) {
	// 1. queens 를 보고 사용 되었는지 확인(같은 열은 사용 불가)
	// 2. 바로 이전의 것 대각선은 사용 불가능함.
	if (queens[cur] == false) {
		if (prev - 1 >= 0)
		{
			if (queens[prev - 1] == false) {
				if (prev + 1 <= n_size) {

				}
			}
		}
			
	}
	else {
		return false;
	}
	
	
	return true;
}


int main() {
	int N, ans = 0;
	vector<int> board;
	cin >> N;
	bool* queens = new bool[N];
	memset(queens, false, N);
	cin >> N;
	for (int i = 0; i < N; i++) {
		// Clear board
		board.clear();
		// Initiate test (Insert first queen)
		board.push_back(i);
		
		

		
	}
	delete[] queens;
	return 0;
}