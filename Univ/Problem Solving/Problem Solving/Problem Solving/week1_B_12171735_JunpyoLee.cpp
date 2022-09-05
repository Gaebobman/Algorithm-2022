#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	string S;
	cin >> T;

	while (T--) {
		cin >> S;
		int max_area = 0 , tmp_area = 0;
		int last_zero_area = 0;
		int t_count = 0;
		int s_length = S.length();
		queue<int> starting_point;		
		vector<int> DP(s_length);		// ���� ������ ������ �����ϴ� DP ���̺� (0���� �ʱ�ȭ ��)	

		// ���������� queue�� ������.
		for (int i = 0; i < s_length; i++) {
			if (S[i] == 'C')
				starting_point.push(i);
			else
				t_count++;

		}

		while (!starting_point.empty()) {
			// ������ ������ ������ ���� �̹� ������ ������ ���� ����
			if (DP[starting_point.front()] == 1) {
				tmp_area = 0;
				starting_point.pop();
				continue;
			}
			//cout << "���� �˻� ����: " << starting_point.front() << endl;
			// �˻縦 ���� �������� �� ����
			DP[starting_point.front()] = 1;
			tmp_area = 1;
			// ���������� ������������ �˻縦 ����
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
				// ���� �˻��ϴ� ������ ���̸� ������Ŵ
				tmp_area++;

				if (DP[i] > t_count) {
					tmp_area = 0;
					break;
				}
				// 1. �������� �ϳ��� �ȳ��� -1�� �� ���, ���� ���� �˻縦 �����Ų��
				if (DP[i] == - 1) {
					max_area = max(max_area, tmp_area - 1);
					tmp_area = 0;
					last_zero_area = 0;
					break;
				}

				// 2. string�� ���������� �˻��� ���
				if (i == s_length - 1) {
					// string�� �������̸� ������������ ����� ���
					if (DP[i] != 0) {
						tmp_area = last_zero_area;
					}
					// �˻縦 �����Ų��.
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

	
	return 0;
}