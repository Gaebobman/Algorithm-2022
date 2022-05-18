#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_USER = 50000;			// 문제에서 주어진 최대 유저 수
const int MAX_FOLLOWER = 500000;	// 문제에서 주어진 최대 팔로우 수
vector<int> adjinfo[MAX_USER + 1];	// 팔로우 정보를 담을 인접 리스트 벡터
vector<int> adjinfo_transpose[MAX_USER + 1];	// 인접 리스트 벡터의 전치
bool visit[MAX_USER + 1];			// 방문정보를 가지는 리스트
std::stack<int> finish_stack;		// DFS의 종료 순서 정보를 갖는 stack
vector<int> follower_number(MAX_USER + 1);	// 유저들의 팔로워 수를 가지는 리스트 (0으로 초기화 됨)
vector<int> parent(MAX_USER + 1);	// vertex들의 부모를 저장하는 벡터

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

void SCC(int vertex) {
	finish_stack.pop();
};

// 유저 a, b의 팔로워 수를 비교하여 팔로워 수가 더 큰 유저로 
// 팔로워 수가 같거나 적다면 사용자 정보가 낮은 순서대로 오름차순 정렬하기 위해 생성한 함수

bool compare(int a, int b) {
	if (follower_number[a] > follower_number[b]) 
		return follower_number[a] > follower_number[b];
	else 
		return a < b;
}

int main() {
	int N, M = 0;	// 사용자 수 N, 팔로워수 M 의 선언
	cin >> N >> M;	// 사용자로부터 N과 M 의 값을 공백으로 구별하여 입력받음
	int user, follow = 0;	// 사용자 1 과 사용자 2 를 입력받을 임시 변수 
	// 사용자들 사이의 팔로우 정보
	for (int i = 0; i < M; i++) {

		cin >> user >> follow;
		adjinfo[user].push_back(follow);	// 인접리스트를 사용 user에게 팔로워 정보 추가
		adjinfo_transpose[follow].push_back(user);
		follower_number[follow]++;
	}

	for (int i = 1; i <= N; i++) {
		// sort(adjinfo[i].begin(), adjinfo[i].end());	// DFS수행시 팔로워의 사용자 정보가 낮은 순서대로 탐색 되도록 오름차순 정렬
		sort(adjinfo[i].begin(), adjinfo[i].end(), compare);	// DFS 수행 조건을 만족시키기 위해 인접리스트를 재 정렬
		sort(adjinfo_transpose[i].begin(), adjinfo_transpose[i].end(), compare);	// DFS 수행 조건을 만족시키기 위해 전치 인접리스트를 재 정렬
	}

	DFS(max_element(follower_number.begin(), follower_number.end()) - follower_number.begin()); // 팔로워가 가장 많은 사용자 부터 DFS 시작
	
	// 도달하지 못한 vertex(사용자)가 있는지 확인
	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {	// 도달하지 못한 사용자를 찾으면
			DFS(i);					// 해당 사용자에 대해 DFS 수행
		}
	}
	cout << endl;

	SCC(finish_stack.top());
	

	return 0;
}
