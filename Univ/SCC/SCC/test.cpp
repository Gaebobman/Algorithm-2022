#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX_NUM = 50001;

stack<int> s;
stack<int> s2;

vector<int> leader(MAX_NUM);            // 리더 저장

vector<bool> is_visited(MAX_NUM);

vector<vector<int>> list(MAX_NUM, vector<int>(1, 0));           // 1 ~ n까지 사용
vector<vector<int>> reverseList(MAX_NUM, vector<int>(1, 0));    // 방향이 바뀐 list

vector<pair<int, int>> followers;       // first: 사용자 번호, second: 팔로워 수

bool compareFollowers(pair<int, int> a, pair<int, int> b) {     // 정점들을 정렬하기 위한 조건 함수
	int ua = a.first, ub = b.first;
	int fa = a.second, fb = b.second;

	if (fa == fb) {
		return ua < ub;
	}

	return fa > fb;
}

bool compareNextNodes(int a, int b) {           // 간선들을 정렬하기 위한 조건 함수
	if (list[a][0] == list[b][0]) {
		return a < b;
	}

	return list[a][0] > list[b][0];
}

void dfs(int curr, vector<vector<int>> list) {
	is_visited[curr] = true;

	// 다음 노드 정렬
	sort(list[curr].begin() + 1, list[curr].end(), compareNextNodes);

	for (int i = 1; i < int(list[curr].size()); i++) {
		int next = list[curr][i];

		if (is_visited[next]) {
			continue;
		}

		dfs(next, list);
	}
	s.push(curr);
}

int main() {
	int n, m;      // 사용자의 수, 팔로우 수
	cin >> n >> m; //n: 사람, m: 간선

	// 데이터 입력
	for (int i = 1; i <= m; i++) {
		int followFrom, followTo;      //   follow하는 사람과, follow당하는 사람
		cin >> followFrom >> followTo;

		list[followFrom].push_back(followTo);
		list[followTo][0]++;      // list[k][0]에는 사용자 k의 팔로워 수 저장

		reverseList[followTo].push_back(followFrom);
		reverseList[followFrom][0]++;
	}

	// 팔로워 수 저장
	for (int i = 1; i <= n; i++) {
		int f = list[i][0];

		followers.push_back(pair<int, int>(i, f)); // first: 사용자 번호, second: 팔로워 수
	}

	// followers 정렬
	sort(followers.begin(), followers.end(), compareFollowers);

	// step 1
	for (int i = 0; i < n; i++) {
		int num = followers[i].first;

		if (is_visited[num])
			continue;

		dfs(num, list);
	}

	stack<int> rs; //reverse
	while (!s.empty()) {
		rs.push(s.top());
		s.pop();
	}

	while (!rs.empty()) {
		cout << rs.top() << ' ';

		s2.push(rs.top());
		rs.pop();
	}
	cout << '\n';

	//step 2
	/*
	is_visited.assign(n + 1, false);

	for (int i = 1; i <= s2.size(); i++) {
		int num = s2.top();
		s2.pop();

		if (is_visited[num])
			continue;

		dfs(num, reverseList);

	}
	*/
	is_visited.assign(n + 1, false);

	for (int i = 1; i <= n; i++) {
		int num = s2.top();
		s2.pop();

		if (is_visited[num])
			continue;

		dfs(num, reverseList);

		while (s.empty() != true) {
			leader[s.top()] = num;
			s.pop();
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << leader[i] << ' ';
	}

	return 0;
}