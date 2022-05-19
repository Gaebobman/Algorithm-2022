#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_USER = 50000;			// 문제에서 주어진 최대 유저 수
const int MAX_FOLLOWER = 500000;	// 문제에서 주어진 최대 팔로우 수
vector<int> adjinfo[MAX_USER + 1];	// 팔로우 정보를 담을 인접 리스트 벡터 (G)
vector<int> adjinfo_transpose[MAX_USER + 1];	// 인접 리스트 벡터의 전치	(G-Transpose)
bool visit[MAX_USER + 1];			// 방문정보를 가지는 리스트 : Vectex에서 DFS 수행 여부를 알기 위함
std::stack<int> finish_stack;		// DFS의 종료 순서 정보를 갖는 stack: 첫 DFS 이후 SCC를 계산하기 위한 Stack
int follower_num_arr[MAX_USER + 1] ;	// 유저들의 팔로워 수를 가지는 array (0으로 초기화 됨): 인접 리스트에서 방문순서조건을 만족시키기 위함
vector<pair<int, int>> follower_num;// 사용자 번호와 사용자의 팔로워 수를 가지는 pair: DFS 수행순서조건(팔로워수, 유저번호)을 만족시키기 위함
vector<int> parent(MAX_USER + 1);	// vertex들의 부모를 저장하는 벡터: SCC 리더 정보임

// 사용자 번호로 DFS를 수행하는 함수
void DFS(int vertex) {
		
	visit[vertex] = true;				// vertex에 대해 방문처리를 해준다.
	for (int i = 0; i < int(adjinfo[vertex].size()); i++) {
		int u = adjinfo[vertex][i];		// 현재 검사중인 vertex(사용자)의 follower를 임시 저장
		if (!visit[u]) { DFS(u); }		// 방문하지 않은 vertex(사용자)에 대해 DFS를 수행
	}
	cout << vertex << ' ';				// 중간정보 출력: 스택에 삽입된 순서대로 사용자들의 번호를 공백으로 구분하여 한 줄에 출력
	finish_stack.push(vertex);
};

void DFS_Transpose(int vertex, int leader) {
	visit[vertex] = false;				// vertex에 대해 방문처리를 해준다(1단계 에서 모든 vertex의 방문여부가  True가 되었다).
	if (int(adjinfo_transpose[vertex].size()) == 0)
		parent[vertex] = leader;
	for (int i = 0; i < int(adjinfo_transpose[vertex].size()); i++) {
		int u = adjinfo_transpose[vertex][i];		// 현재 검사중인 vertex(사용자)의 follower를 임시 저장
		if (visit[u]) {
			parent[u] = leader;	// SCC 리더 정보를 업데이트
			DFS_Transpose(u, leader);	// 방문하지 않은 vertex(사용자)에 대해 DFS를 수행
		}
	}
};

void SCC(int vertex, int leader) {
	finish_stack.pop();
	if (visit[vertex])	// 방문하지 않은 Vertex 이면
		parent[vertex] = leader;
		DFS_Transpose(vertex, leader);	// 전치행렬에서의 DFS 실행
};

// 인접리스트에서 사용하는 Compare 함수.
// 유저 a, b의 팔로워 수를 비교하여 팔로워 수가 더 큰 유저로 
// 팔로워 수가 같다면 사용자 정보가 낮은 순서대로 오름차순 정렬하기 위해 생성한 함수
bool compare(int a, int b) {
	if (follower_num_arr[a] == follower_num_arr[b])		// 유저 a, b의 팔로워 수를 비교, 팔로워 수가 같다면
		return a < b;	// 사용자 정보가 낮은 순서대로 오름차순 정렬
	else							// 팔로워수가 같지 않다면
		return follower_num_arr[a] > follower_num_arr[b];	// 팔로워수로 내림차순 정렬
}


// DFS 시작원소가 항상 조건(팔로워수 와 유저번호)에 맞도록 실행하기 위한 Compare 함수.
// 첫 DFS로 도달하지 못한 원소에 대해서도 팔로워수 조건과 유저 번호 조건을 만족시킴
// 유저 a, b의 팔로워 수를 비교하여 팔로워 수가 더 큰 유저로 
// 팔로워 수가 같다면 사용자 정보가 낮은 순서대로 오름차순 정렬하기 위해 생성한 함수
bool compare_follower(pair<int,int> a, pair<int, int> b) {
	if (a.second == b.second)		// 유저 a, b의 팔로워 수를 비교, 팔로워 수가 같다면
		return a.first < b.first;	// 사용자 정보가 낮은 순서대로 오름차순 정렬
	else							// 팔로워수가 같지 않다면
		return a.second > b.second;	// 팔로워수로 내림차순 정렬
}

int main() {
	int N, M = 0;	// 사용자 수 N, 팔로워수 M 의 선언
	cin >> N >> M;	// 사용자로부터 N과 M 의 값을 공백으로 구별하여 입력받음
	int user, follow = 0;	// 사용자 1 과 사용자 2 를 입력받을 임시 변수 
	// 사용자들 사이의 팔로우 정보
	for (int i = 0; i < M; i++) {
		cin >> user >> follow;				// 사용자로부터 필드 1, 필드 2를 입력 받음
		adjinfo[user].push_back(follow);	// 인접리스트를 사용 user에게 팔로워 정보 추가	(G)
		adjinfo_transpose[follow].push_back(user);	// G-Transpose	
		follower_num_arr[follow]++;			// 팔로워가 늘 때 마다 팔로워수를 Update
	}

	for (int i = 1; i <= N; i++) {
		sort(adjinfo[i].begin(), adjinfo[i].end(), compare);	// DFS 수행 조건을 만족시키기 위해 인접리스트(G)를 재 정렬
		sort(adjinfo_transpose[i].begin(), adjinfo_transpose[i].end(), compare);	// DFS 수행 조건을 만족시키기 위해 전치 인접리스트(G-T)를 재 정렬
		follower_num.push_back(make_pair(i, follower_num_arr[i]));		// 수행조건(팔로워수, 유저번호)을 만족시키기 위해 유지하는 vector
	}
	sort(follower_num.begin(), follower_num.end(),compare_follower);
	DFS(follower_num[0].first); // 팔로워가 가장 많은 사용자 부터 DFS 시작
	
	// 도달하지 못한 vertex(사용자)가 있는지 확인
	for (int i = 0; i < N; i++) {
		if (visit[follower_num[i].first] == false) {	// 도달하지 못한 사용자를 찾으면
			DFS(follower_num[i].first);					// 해당 사용자에 대해 DFS 수행
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
