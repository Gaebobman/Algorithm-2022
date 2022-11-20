#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, A, B, X;
	cin >> T;
	// X: ��� �̹� �� �Ÿ�
	// A: �ѹ��� �޸� �ð�
	// B: ���� �ð�
	while (T--) {
		// �ѹ��� �̵��ϴ� �Ÿ� == A * 2;
		// �ѹ��� �̵� ���ɰŸ��� ������ �׶� ���
		// �ʴ� 1���;� �������
		int pos_bi, pos_to = 0;
		cin >> X >> A >> B;
		pos_bi = X; // �ʱ� ����� ��ġ ����
		int result = 0;	// �ɸ�  �ð�
		int one_hop = A * 2;
		while (pos_bi != pos_to) {
			// �̹� �Ͽ� ���� �� ������
			if (pos_to + one_hop >= pos_bi + A) {
				result += (pos_bi - pos_to);
				break;
			}
			else {
				// ����� ���������� �Ѿ��
				result += (A + B); // �ѹ� HOP, �޽�
				pos_to += one_hop;	// ��ġ ������Ʈ
				pos_bi += (A + B);	// ����
			}
		}

		cout << result + X << '\n';
	}
	return 0;
}