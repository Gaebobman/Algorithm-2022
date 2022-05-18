#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_USER = 50000;			// �������� �־��� �ִ� ���� ��
const int MAX_FOLLOWER = 500000;	// �������� �־��� �ִ� �ȷο� ��
vector<int> adjinfo[MAX_USER + 1];	// �ȷο� ������ ���� ���� ����Ʈ ����
bool visit[MAX_USER + 1];			// �湮������ ������ ����Ʈ
std::stack<int> finish_stack;		// DFS�� ���� ���� ������ ���� stack
vector<int> follower_number(MAX_USER + 1);	// �������� �ȷο� ���� ������ ����Ʈ (0���� �ʱ�ȭ ��)


// ����� ��ȣ�� DFS�� �����ϴ� �Լ�
void DFS(int vertex) {
		
	visit[vertex] = true;				// vertex�� ���� �湮ó���� ���ش�.
	for (int i = 0; i < int(adjinfo[vertex].size()); i++) {
		int u = adjinfo[vertex][i];		// ���� �˻����� vertex(�����)�� follower�� �ӽ� ����
		if (!visit[u]) { DFS(u); }		// �湮���� ���� vertex(�����)�� ���� DFS�� ����
	}
	cout << vertex << ' ';				// �߰����� ���: ���ÿ� ���Ե� ������� ����ڵ��� ��ȣ�� �������� �����Ͽ� �� �ٿ� ���
	finish_stack.push(vertex);
};

// ���� a, b�� �ȷο� ���� ���Ͽ� �ȷο� ���� �� ū ������ �������� �����ϱ� ���� ������ �Լ�
int compare(int a, int b) {
	return follower_number[a] < follower_number[b];
}

int main() {
	int N, M = 0;	// ����� �� N, �ȷο��� M �� ����
	cin >> N >> M;	// ����ڷκ��� N�� M �� ���� �������� �����Ͽ� �Է¹���
	int user, follow = 0;	// ����� 1 �� ����� 2 �� �Է¹��� �ӽ� ���� 
	// ����ڵ� ������ �ȷο� ����
	for (int i = 0; i < M; i++) {
		cin >> user >> follow;
		adjinfo[user].push_back(follow);	// ��������Ʈ�� ��� user���� �ȷο� ���� �߰�
		follower_number[follow]++;
	}

	for (int i = 1; i <= N; i++) {
		sort(adjinfo[i].begin(), adjinfo[i].end());	// DFS����� �ȷο��� ����� ������ ���� ������� Ž�� �ǵ��� �������� ����
		sort(adjinfo[i].begin(), adjinfo[i].end(), compare);	// �ȷο� �� ��� �ٽ� ����
	}

	DFS(max_element(follower_number.begin(), follower_number.end()) - follower_number.begin()); // �ȷο��� ���� ���� ����� ���� DFS ����
	
	// �������� ���� vertex(�����)�� �ִ��� Ȯ��
	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {	// �������� ���� ����ڸ� ã����
			DFS(i);					// �ش� ����ڿ� ���� DFS ����
		}
	}
	cout << endl;

	return 0;
}
