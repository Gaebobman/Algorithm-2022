#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N;	// Length of Text 
int M;	// Length of Pattern
vector<int> string_start_index;	// ������ �����ϴ� ������ġ�� ����


// Faliure function (Pattern�� ��ó�� ����) : O(m) time
vector<int> failure_function(string pattern) {
	vector<int> f_table(M);		// Pattern ���� ��ŭ�� failure_table ����
	f_table[0] = 0;		// ù ���Ҵ� �׻� 0
	int I = 1;	// Suffix index
	int J = 0;	// Prefix index
	while (I < M) {
		if (pattern[I] == pattern[J]) {
			// J + 1 character�� Match �� ����
			f_table[I] = J + 1;
			I += 1;
			J += 1;
		}
		else if (J > 0) {
			// f_table�� �̿��Ͽ� Pattern shift
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
	vector<int> F = failure_function(pattern);	// failure_table �� ����
	int I = 0;	// index of Text
	int J = 0;	// index of Pattern
	
	// Text�� ���̸�ŭ �ݺ�
	while (I < N) {
		if (text[I] == pattern[J]) {	// Case 1 (text�� character�� pattern�� character �ΰ��� match)
			if (J == M - 1) {	// ������ character ���� ��ġ�ϴ� ���
				string_start_index.push_back(I - J);	// ������ �����ϴ� ��ġ ����
				J = F[J];
				//if (J == F[M - 1]) {
				//	cout << 1 << " ";
				//}
			}
			// ���� Character �񱳸� ���� idx++;
			else {
				I += 1;
				J += 1;
			}
		}
		else if (J > 0) {
			// (1) �˰��� ���� �� �߰����� ���
			cout << J + (F[J-1] + 1) << " ";		// Shift ������ ���
			J = F[J - 1];	// Pattern�� ���������� shift;
		}
		else {
			I += 1;
			cout << J + 1 << " ";
		}
			
	}
}

int main() {
	// (0) ������ �Է¹ޱ�
	string text;		// Text(å�� ����)
	string pattern;		// Pattern(����)
	cin >> text;
	cin >> pattern;
	N = text.length();		// Text�� ���̸� ����
	M = pattern.length();	// Pattern�� ���̸� ����

	// (1) �˰��� ���� �� �߰����� ���
	KMP(text, pattern);
	cout << endl;
	// (2) �˰��� ���� �� ���� ���
	for (int i = 0; i < string_start_index.size(); i++) {
		cout << string_start_index[i] << " ";
	}


	return 0;
}