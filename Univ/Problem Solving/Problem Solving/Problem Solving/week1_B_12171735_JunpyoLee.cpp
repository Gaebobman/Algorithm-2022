#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	string S;
	cin >> T;

	while (T--) {
		stack<int> my_stack, my_stack_2;
		int max_size = 0, tmp_size = 0;
		cin >> S;
		int s_length = S.length();
		for (int i = 0; i < s_length; i++) {
			// 1. T가 나온 상황
			if (S[i] == 'T') {
				// Empty stack 인 경우
				if (my_stack.empty()) {
					tmp_size = 0;
					continue;
				}
				else {
					my_stack.pop();
					tmp_size++;
					if (my_stack.empty()) {
						max_size = max(max_size, tmp_size);
					}

				}
			}
			// 2. C가 나온 상황
			else {
				my_stack.push('C');
				tmp_size++;
			}
		}
		tmp_size = 0;
		for (int i = s_length - 1; i >= 0; i--) {
			// 1. C가 나온 상황
			if (S[i] == 'C') {
				// Empty stack 인 경우
				if (my_stack_2.empty()) {
					tmp_size = 0;
					continue;
				}
				else {
					my_stack_2.pop();
					tmp_size++;
					if (my_stack_2.empty()) {
						max_size = max(max_size, tmp_size);
					}

				}
			}
			// 2. T가 나온 상황
			else {
				my_stack_2.push('T');
				tmp_size++;
			}
		}

		cout << max_size << '\n';
	}

	/*
	while (T--) {
		cin >> S;
		int max_area = 0 , tmp_area = 0;
		int last_zero_area = 0;
		int t_count = 0;
		int s_length = S.length();
		queue<int> starting_point;
		vector<int> DP(s_length);		// 시작 가능한 지점을 저장하는 DP 테이블 (0으로 초기화 함)

		// 시작점들을 queue에 저장함.
		for (int i = 0; i < s_length; i++) {
			if (S[i] == 'C')
				starting_point.push(i);
			else
				t_count++;

		}

		while (!starting_point.empty()) {
			// 이전에 연산한 내용을 토대로 이미 실행한 연산은 하지 않음
			if (DP[starting_point.front()] == 1) {
				tmp_area = 0;
				starting_point.pop();
				continue;
			}
			//cout << "현재 검사 영역: " << starting_point.front() << endl;
			// 검사를 위해 시작지점 값 설정
			DP[starting_point.front()] = 1;
			tmp_area = 1;
			// 시작지점의 다음지점부터 검사를 시작
			for (int i = starting_point.front() + 1; i < s_length; i++) {

				if (S[i] == 'C') {
					cout << "idx: " << i << "[C]" ;
					DP[i] = DP[i - 1] + 1;
				}
				else {
					cout << "idx: " << i << "[T] ";
					DP[i] = DP[i - 1] - 1;
					if (DP[i] == 0) {
						last_zero_area = tmp_area + 1;
					}
				}
				cout << "DP[" << i << "] = " << DP[i] << endl;
				// 현재 검사하는 영역의 길이를 증가시킴
				tmp_area++;

				if (DP[i] > t_count) {
					tmp_area = 0;
					break;
				}
				// 1. 게이지가 하나도 안남고 -1이 된 경우, 현재 영역 검사를 종료시킨다
				if (DP[i] == - 1) {
					max_area = max(max_area, tmp_area - 1);
					tmp_area = 0;
					last_zero_area = 0;
					break;
				}

				// 2. string의 마지막까지 검사한 경우
				if (i == s_length - 1) {
					// string의 마지막이며 비정상적으로 종료된 경우
					if (DP[i] != 0) {
						tmp_area = last_zero_area;
					}
					// 검사를 종료시킨다.
					max_area = max(max_area, tmp_area);
					tmp_area = 0;
					last_zero_area = 0;
					break;
				}
			}
			starting_point.pop();
		}
		cout << max_area << '\n';
	}
	*/

	return 0;
}