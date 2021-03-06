#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> L(26, -1);	// 26개의 알파벳의 Last occurence 정보를 담을 vector
vector<int> string_start_index;	// 구문이 존재하는 시작위치를 저장
int N;	// Length of Text 
int M;	// Length of Pattern


// Last occurence: L 을 계산 후 반환 하는 Function
void last_occurrence(string pattern) {
	int last_x_idx = -1;
	for (int i = 0; i < pattern.length(); i++) {	// 패턴내에 X가 존재하는지 확인을 하여
		if (pattern[i] == 'X') {				// X의 위치를 알아냄
			last_x_idx = i;
		}
	}

	if (last_x_idx == -1) {
		for (int i = last_x_idx + 1; i < pattern.size(); i++) {		// X가 존재하지 않는 경우는 자기 자신이 Last occurence 위치임
			L[pattern[i] - 'a'] = i;
		}
	}
	else {		// X가 존재하는 경우
		for (int i = 0; i < pattern.length(); i++) {
			if (pattern[i] == 'X') {	// 현재 검사하는것이 'X' 이면 넘어감
				continue;
			}
			if (i > last_x_idx) {		// 패턴에 X가 존재하는데 X 뒤에 있는 문자(O)에 대한 처리 ( ~~~~~X OOOOO)
				L[pattern[i]- 'a'] = i;
				continue;
			}
			L[pattern[i] - 'a'] = last_x_idx;	// 패턴에 X가 존재하는데 X 앞에 있는 문자(O)에 대한 처리 ( OOOOO X ~~~~)
		}

		for (int i = 0; i < L.size(); i++) {
			if (L[i] == -1) {
				L[i] = last_x_idx;
			}
		}
	}
}


void boyerMooreMatch(string text, string pattern) {
	int I = M - 1;	// I는 현재 비교하는 Text의 Index, 
	int J = M - 1;	// J는 현재 비교하는 Pattern의 Index
	if (N < M) {
		// Text길이보다 Pattern 의 길이가 더 긴경우
		// Do Nothing
	}
	else {
		do {
			if (text[I] == pattern[J] || pattern[J] == 'X') {	// 두 Character가 일치하는 경우, 또는 패턴의 charcter가 'X' (모든 문자가 될 수있는 문자) 인 경우
				if (J == 0) {		// 모든 문자가 매치완료 된 경우 (Pattern과 일치하는 구문을 찾음)
					string_start_index.push_back(I);
					cout << "1" << " ";		// 모든 문자가 매치된 경우 패턴이 한 칸 밀린다
					I += M;		// 패턴 전체 크기만큼 확인할 문자를 이동
					J = M - 1;	// 패턴 마지막 문자부터 다시 비교 시작
				}
				else {		// 비교할 것이 더 남은 경우
					I -= 1;
					J -= 1;
				}
			}
			else {
				int _L = L[text[I] - 'a'];		// Case 2에서 사용할 _L
				int tmp_shift_text = 0;
				if (J < _L + 1) {
					cout << "1" << " ";
					tmp_shift_text = M - J;
				}
				else {
					cout << J - _L << " ";
					tmp_shift_text = M - _L - 1;
				}
				I = I + tmp_shift_text;		// J는 Case 1 일때 , 1 + _L 은 Case 2 일때 
				J = M - 1;
			}
		} while (I < N);
	}
}

int main() {
	string text;		// 입력받을 Text
	string pattern;		// 입력받을 Pattern
	// (0) 데이터 입력받기
	cin >> text;
	cin >> pattern;
	last_occurrence(pattern);
	N = text.length();
	M = pattern.length();

	// (1) 알고리즘 진행 중 중간정보 출력
	boyerMooreMatch(text, pattern);
	cout << endl;
	// (2) 알고리즘 종료 후 정보 출력

	for (int i = 0; i < string_start_index.size(); i++) {
		cout << string_start_index[i] << " ";
	}
	cout << endl;
	return 0;
}