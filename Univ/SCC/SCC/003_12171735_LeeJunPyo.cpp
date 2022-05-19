#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_USER = 50000;			// �������� �־��� �ִ� ���� ��
const int MAX_FOLLOWER = 500000;	// �������� �־��� �ִ� �ȷο� ��
vector<int> adjinfo[MAX_USER + 1];	// �ȷο� ������ ���� ���� ����Ʈ ���� (G)
vector<int> adjinfo_transpose[MAX_USER + 1];	// ���� ����Ʈ ������ ��ġ	(G-Transpose)
bool visit[MAX_USER + 1];			// �湮������ ������ ����Ʈ : Vectex���� DFS ���� ���θ� �˱� ����
std::stack<int> finish_stack;		// DFS�� ���� ���� ������ ���� stack: ù DFS ���� SCC�� ����ϱ� ���� Stack
int follower_num_arr[MAX_USER + 1] ;	// �������� �ȷο� ���� ������ array (0���� �ʱ�ȭ ��): ���� ����Ʈ���� �湮���������� ������Ű�� ����
vector<pair<int, int>> follower_num;// ����� ��ȣ�� ������� �ȷο� ���� ������ pair: DFS �����������(�ȷο���, ������ȣ)�� ������Ű�� ����
vector<int> parent(MAX_USER + 1);	// vertex���� �θ� �����ϴ� ����: SCC ���� ������

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

void DFS_Transpose(int vertex, int leader) {
	visit[vertex] = false;				// vertex�� ���� �湮ó���� ���ش�(1�ܰ� ���� ��� vertex�� �湮���ΰ�  True�� �Ǿ���).
	if (int(adjinfo_transpose[vertex].size()) == 0)
		parent[vertex] = leader;
	for (int i = 0; i < int(adjinfo_transpose[vertex].size()); i++) {
		int u = adjinfo_transpose[vertex][i];		// ���� �˻����� vertex(�����)�� follower�� �ӽ� ����
		if (visit[u]) {
			parent[u] = leader;	// SCC ���� ������ ������Ʈ
			DFS_Transpose(u, leader);	// �湮���� ���� vertex(�����)�� ���� DFS�� ����
		}
	}
};

void SCC(int vertex, int leader) {
	finish_stack.pop();
	if (visit[vertex])	// �湮���� ���� Vertex �̸�
		parent[vertex] = leader;
		DFS_Transpose(vertex, leader);	// ��ġ��Ŀ����� DFS ����
};

// ��������Ʈ���� ����ϴ� Compare �Լ�.
// ���� a, b�� �ȷο� ���� ���Ͽ� �ȷο� ���� �� ū ������ 
// �ȷο� ���� ���ٸ� ����� ������ ���� ������� �������� �����ϱ� ���� ������ �Լ�
bool compare(int a, int b) {
	if (follower_num_arr[a] == follower_num_arr[b])		// ���� a, b�� �ȷο� ���� ��, �ȷο� ���� ���ٸ�
		return a < b;	// ����� ������ ���� ������� �������� ����
	else							// �ȷο����� ���� �ʴٸ�
		return follower_num_arr[a] > follower_num_arr[b];	// �ȷο����� �������� ����
}


// DFS ���ۿ��Ұ� �׻� ����(�ȷο��� �� ������ȣ)�� �µ��� �����ϱ� ���� Compare �Լ�.
// ù DFS�� �������� ���� ���ҿ� ���ؼ��� �ȷο��� ���ǰ� ���� ��ȣ ������ ������Ŵ
// ���� a, b�� �ȷο� ���� ���Ͽ� �ȷο� ���� �� ū ������ 
// �ȷο� ���� ���ٸ� ����� ������ ���� ������� �������� �����ϱ� ���� ������ �Լ�
bool compare_follower(pair<int,int> a, pair<int, int> b) {
	if (a.second == b.second)		// ���� a, b�� �ȷο� ���� ��, �ȷο� ���� ���ٸ�
		return a.first < b.first;	// ����� ������ ���� ������� �������� ����
	else							// �ȷο����� ���� �ʴٸ�
		return a.second > b.second;	// �ȷο����� �������� ����
}

int main() {
	int N, M = 0;	// ����� �� N, �ȷο��� M �� ����
	cin >> N >> M;	// ����ڷκ��� N�� M �� ���� �������� �����Ͽ� �Է¹���
	int user, follow = 0;	// ����� 1 �� ����� 2 �� �Է¹��� �ӽ� ���� 
	// ����ڵ� ������ �ȷο� ����
	for (int i = 0; i < M; i++) {
		cin >> user >> follow;				// ����ڷκ��� �ʵ� 1, �ʵ� 2�� �Է� ����
		adjinfo[user].push_back(follow);	// ��������Ʈ�� ��� user���� �ȷο� ���� �߰�	(G)
		adjinfo_transpose[follow].push_back(user);	// G-Transpose	
		follower_num_arr[follow]++;			// �ȷο��� �� �� ���� �ȷο����� Update
	}

	for (int i = 1; i <= N; i++) {
		sort(adjinfo[i].begin(), adjinfo[i].end(), compare);	// DFS ���� ������ ������Ű�� ���� ��������Ʈ(G)�� �� ����
		sort(adjinfo_transpose[i].begin(), adjinfo_transpose[i].end(), compare);	// DFS ���� ������ ������Ű�� ���� ��ġ ��������Ʈ(G-T)�� �� ����
		follower_num.push_back(make_pair(i, follower_num_arr[i]));		// ��������(�ȷο���, ������ȣ)�� ������Ű�� ���� �����ϴ� vector
	}
	sort(follower_num.begin(), follower_num.end(),compare_follower);
	DFS(follower_num[0].first); // �ȷο��� ���� ���� ����� ���� DFS ����
	
	// �������� ���� vertex(�����)�� �ִ��� Ȯ��
	for (int i = 0; i < N; i++) {
		if (visit[follower_num[i].first] == false) {	// �������� ���� ����ڸ� ã����
			DFS(follower_num[i].first);					// �ش� ����ڿ� ���� DFS ����
		}
	}
	cout << endl;


	while(!finish_stack.empty())
		SCC(finish_stack.top(), finish_stack.top());
	for (int i = 1; i <= N; i++)
		cout << parent[i] << ' ';
	cout << endl;


	return 0;
}
