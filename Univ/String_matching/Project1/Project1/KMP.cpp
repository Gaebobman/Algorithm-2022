#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N;	// Length of Text 
int M;	// Length of Pattern
vector<int> string_start_index;	// 구문이 존재하는 시작위치를 저장


// Faliure function (Pattern의 전처리 과정) : O(m) time
vector<int> failure_function(string pattern) {
	vector<int> f_table(M);		// Pattern 길이 만큼의 failure_table 정의
	f_table[0] = 0;		// 첫 원소는 항상 0
	int I = 1;	// Suffix index
	int J = 0;	// Prefix index
	while (I < M) {
		if (pattern[I] == pattern[J]) {
			// J + 1 character를 Match 한 상태
			f_table[I] = J + 1;
			I += 1;
			J += 1;
		}
		else if (J > 0) {
			// f_table을 이용하여 Pattern shift
			J = f_table[J - 1];
		}
		else {
			f_table[I] = 0;
			I += 1;
		}
	}
	return f_table;
}

// KMP algorithm
void KMP(string text, string pattern) {
	vector<int> F = failure_function(pattern);	// failure_table 을 저장
	int I = 0;	// index of Text
	int J = 0;	// index of Pattern
	
	// Text의 길이만큼 반복
	while (I < N) {
		if (text[I] == pattern[J]) {	// Case 1 (text의 character와 pattern의 character 두개가 match)
			if (J == M - 1) {	// 마지막 character 까지 일치하는 경우
				string_start_index.push_back(I - J);	// 구문이 시작하는 위치 저장
				J = F[J];
				//if (J == F[M - 1]) {
				//	cout << 1 << " ";
				//}
			}
			// 다음 Character 비교를 위해 idx++;
			else {
				I += 1;
				J += 1;
			}
		}
		else if (J > 0) {
			// (1) 알고리즘 진행 중 중간정보 출력
			cout << J + (F[J-1] + 1) << " ";		// Shift 정보를 출력
			J = F[J - 1];	// Pattern을 오른쪽으로 shift;
		}
		else {
			I += 1;
			cout << J + 1 << " ";
		}
			
	}
}

int main() {
	// (0) 데이터 입력받기
	string text;		// Text(책의 내용)
	string pattern;		// Pattern(구문)
	cin >> text;
	cin >> pattern;
	N = text.length();		// Text의 길이를 저장
	M = pattern.length();	// Pattern의 길이를 저장

	// (1) 알고리즘 진행 중 중간정보 출력
	KMP(text, pattern);
	cout << endl;
	// (2) 알고리즘 종료 후 정보 출력
	for (int i = 0; i < string_start_index.size(); i++) {
		cout << string_start_index[i] << " ";
	}


	return 0;
}