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
	if (pattern.rfind('X') != string::npos) {	// X가 패턴에 존재하는 경우
		int last_x_idx = pattern.rfind('X');	// X의 마지막 발생 위치를 저장
		for (int i = 0; i < last_x_idx; i++) {	// 패턴 내에서 X 앞에 있는 알파벳들은 
			L[i] = last_x_idx;					// X위치로 Update
		}
		for (int i = last_x_idx + 1; i < pattern.size(); i++) {		// 그 이후의 알파벳들은 자기 자신이 Last occurence 위치임
			L[pattern[i] - 'a'] = i;
		}
	}
	else {		// X가 패턴에 존재하지 않는 경우
		for (int i = 0; i < pattern.size(); i++) {		// pattern 의 원소를 순회하며 L을 Update
			L[pattern[i] - 'a'] = i;
		}
	}
}


void boyerMooreMatch(string text, string pattern) {
	int I = M - 1;	// I는 현재 비교하는 Text의 Index, 
	int J = M - 1;	// J는 현재 비교하는 Pattern의 Index
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
			if (J < _L + 1) {
				cout << "1" << " ";
			}
			else {
				cout << J - _L << " ";
			}
			I = I + M - min(J, 1 + _L);		// J는 Case 1 일때 , 1 + _L 은 Case 2 일때 
			J = M - 1;
		}
	} while (I < N);
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
	return 0;
}