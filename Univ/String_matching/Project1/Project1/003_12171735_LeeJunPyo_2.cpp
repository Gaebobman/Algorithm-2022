#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> L(26, -1);	// 26���� ���ĺ��� Last occurence ������ ���� vector
vector<int> string_start_index;	// ������ �����ϴ� ������ġ�� ����
int N;	// Length of Text 
int M;	// Length of Pattern


// Last occurence: L �� ��� �� ��ȯ �ϴ� Function
void last_occurrence(string pattern) {
	int last_x_idx = -1;
	for (int i = 0; i < pattern.length(); i++) {	// ���� ������ X �տ� �ִ� ���ĺ����� 
		if (pattern[i] == 'X') {				// X��ġ�� Update
			last_x_idx = i;
		}
	}
	if (last_x_idx == -1) {
		for (int i = last_x_idx + 1; i < pattern.size(); i++) {		// X�� �������� �ʴ� ���� �ڱ� �ڽ��� Last occurence ��ġ��
			L[pattern[i] - 'a'] = i;
		}
	}
	else {		// X�� �����ϴ� ���
		for (int i = 0; i < pattern.length(); i++) {
			if (pattern[i] == 'X') {
				continue;
			}
			L[pattern[i] - 'a'] = last_x_idx;
			if (L[pattern[i] - 'a'] < pattern[i] - 'a') {
				L[pattern[i] - 'a'] = pattern[i] - 'a';
			}
		}

		for (int i = 0; i < L.size(); i++) {
			if (L[i] == -1) {
				L[i] = last_x_idx;
			}
		}
	}

	/*
	if (pattern.rfind('X') != string::npos) {	// X�� ���Ͽ� �����ϴ� ���
		int last_x_idx = pattern.rfind('X');	// X�� ������ �߻� ��ġ�� ����
		for (int i = 0; i < last_x_idx; i++) {	// ���� ������ X �տ� �ִ� ���ĺ����� 
			L[i] = last_x_idx;					// X��ġ�� Update
		}
		for (int i = last_x_idx + 1; i < pattern.size(); i++) {		// �� ������ ���ĺ����� �ڱ� �ڽ��� Last occurence ��ġ��
			L[pattern[i] - 'a'] = i;
		}
		for (int i = 0; i < L.size(); i++) {
			if (L[i] == -1) {
				L[i] = last_x_idx;
			}
		}
	}
	else {		// X�� ���Ͽ� �������� �ʴ� ���
		for (int i = 0; i < pattern.size(); i++) {		// pattern �� ���Ҹ� ��ȸ�ϸ� L�� Update
			L[pattern[i] - 'a'] = i;
		}
	}
	*/
}


void boyerMooreMatch(string text, string pattern) {
	int I = M - 1;	// I�� ���� ���ϴ� Text�� Index, 
	int J = M - 1;	// J�� ���� ���ϴ� Pattern�� Index
	if (N < M) {
		// Text���̺��� Pattern �� ���̰� �� ����
		// Do Nothing
	}
	else {

	do {
		if (text[I] == pattern[J] || pattern[J] == 'X') {	// �� Character�� ��ġ�ϴ� ���, �Ǵ� ������ charcter�� 'X' (��� ���ڰ� �� ���ִ� ����) �� ���
			if (J == 0) {		// ��� ���ڰ� ��ġ�Ϸ� �� ��� (Pattern�� ��ġ�ϴ� ������ ã��)
				string_start_index.push_back(I);
				cout << "1" << " ";		// ��� ���ڰ� ��ġ�� ��� ������ �� ĭ �и���
				I += M;		// ���� ��ü ũ�⸸ŭ Ȯ���� ���ڸ� �̵�
				J = M - 1;	// ���� ������ ���ں��� �ٽ� �� ����
			}
			else {		// ���� ���� �� ���� ���
				I -= 1;
				J -= 1;
			}
		}
		else {
			int _L = L[text[I] - 'a'];		// Case 2���� ����� _L
			int tmp_shift_text = 0;
			if (J < _L + 1) {
				cout << "1" << " ";
				tmp_shift_text = M - J;
			}
			else {
				cout << J - _L << " ";
				tmp_shift_text = M - _L - 1;
			}
			I = I + tmp_shift_text;		// J�� Case 1 �϶� , 1 + _L �� Case 2 �϶� 
			J = M - 1;
		}
	} while (I < N);
	}
}

int main() {
	string text;		// �Է¹��� Text
	string pattern;		// �Է¹��� Pattern
	// (0) ������ �Է¹ޱ�
	cin >> text;
	cin >> pattern;
	last_occurrence(pattern);
	N = text.length();
	M = pattern.length();
	
	// (1) �˰��� ���� �� �߰����� ���
	boyerMooreMatch(text, pattern);
	cout << endl;
	// (2) �˰��� ���� �� ���� ���

	for (int i = 0; i < string_start_index.size(); i++) {
		cout << string_start_index[i] << " ";
	}
	
	return 0;
}