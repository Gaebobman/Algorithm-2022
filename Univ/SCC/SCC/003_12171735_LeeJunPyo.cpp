#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_USER = 50000;			// �������� �־��� �ִ� ���� ��
const int MAX_FOLLOWER = 500000;	// �������� �־��� �ִ� �ȷο� ��
vector<int> adjinfo[MAX_USER + 1];	// �ȷο� ������ ���� ���� ����Ʈ ����
vector<int> adjinfo_transpose[MAX_USER + 1];	// ���� ����Ʈ ������ ��ġ
bool visit[MAX_USER + 1];			// �湮������ ������ ����Ʈ
std::stack<int> finish_stack;		// DFS�� ���� ���� ������ ���� stack
vector<int> follower_number(MAX_USER + 1);	// �������� �ȷο� ���� ������ ����Ʈ (0���� �ʱ�ȭ ��)
vector<int> parent(MAX_USER + 1);	// vertex���� �θ� �����ϴ� ����

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

void SCC(int vertex) {
	finish_stack.pop();
};

// ���� a, b�� �ȷο� ���� ���Ͽ� �ȷο� ���� �� ū ������ 
// �ȷο� ���� ���ų� ���ٸ� ����� ������ ���� ������� �������� �����ϱ� ���� ������ �Լ�

bool compare(int a, int b) {
	if (follower_number[a] > follower_number[b]) 
		return follower_number[a] > follower_number[b];
	else 
		return a < b;
}

int main() {
	int N, M = 0;	// ����� �� N, �ȷο��� M �� ����
	cin >> N >> M;	// ����ڷκ��� N�� M �� ���� �������� �����Ͽ� �Է¹���
	int user, follow = 0;	// ����� 1 �� ����� 2 �� �Է¹��� �ӽ� ���� 
	// ����ڵ� ������ �ȷο� ����
	for (int i = 0; i < M; i++) {

		cin >> user >> follow;
		adjinfo[user].push_back(follow);	// ��������Ʈ�� ��� user���� �ȷο� ���� �߰�
		adjinfo_transpose[follow].push_back(user);
		follower_number[follow]++;
	}

	for (int i = 1; i <= N; i++) {
		// sort(adjinfo[i].begin(), adjinfo[i].end());	// DFS����� �ȷο��� ����� ������ ���� ������� Ž�� �ǵ��� �������� ����
		sort(adjinfo[i].begin(), adjinfo[i].end(), compare);	// DFS ���� ������ ������Ű�� ���� ��������Ʈ�� �� ����
		sort(adjinfo_transpose[i].begin(), adjinfo_transpose[i].end(), compare);	// DFS ���� ������ ������Ű�� ���� ��ġ ��������Ʈ�� �� ����
	}

	DFS(max_element(follower_number.begin(), follower_number.end()) - follower_number.begin()); // �ȷο��� ���� ���� ����� ���� DFS ����
	
	// �������� ���� vertex(�����)�� �ִ��� Ȯ��
	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {	// �������� ���� ����ڸ� ã����
			DFS(i);					// �ش� ����ڿ� ���� DFS ����
		}
	}
	cout << endl;

	SCC(finish_stack.top());
	

	return 0;
}
