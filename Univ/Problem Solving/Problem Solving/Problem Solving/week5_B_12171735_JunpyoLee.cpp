#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N = 0, M = 0, y, t;
	string s, s1, s2;
	cin >> T;
	while (T--) {
		vector<pair<string, int>> history;
		map<string, int> city_with_key;		//Name / index
		cin >> N >> M;
		// vector<pair<int, int>> G[50001];	// Graph(DST, TIME);
		vector<pair<int, int>> G[50001];	// Graph(DST, TIME);
		vector<int> time(N+1);
		vector<int> indegree(N + 1);
		queue<int> q;

		for (int i = 0; i < N; i++) {
			cin >> s >> y;
			history.push_back(make_pair(s, y));
		}

		sort(history.begin(), history.end(), compare);
		
		for (int i = 1; i <= N; i++) {
			city_with_key.insert({ history[i - 1].first, i });
		}

		for (int i = 0; i < M; i++) {
			// 문제의 조건에 의하면 Graph는 DAG 임 
			cin >> s1 >> s2 >> t;
			auto s1_key = city_with_key.find(s1) -> second;
			auto s2_key = city_with_key.find(s2) -> second;
			G[min(s1_key, s2_key)].push_back({max(s1_key, s2_key), t});
			indegree[max(s1_key, s2_key)]++;
		}
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		for (int i = 1; i <= N; i++) {
			int front = q.front();
			q.pop();
			while (!G[front].empty()) {
				// 도착지점의 시간은 = MAX( 출발지점이 가진 시간 + 도착지점까지 가는시간, 도착지점이 가진 시간 ) 
				time[G[front].back().first] = max(time[front] + G[front].back().second, time[G[front].back().first]);
				if (--indegree[G[front].back().first] == 0) {
					q.push(G[front].back().first);
				}
				G[front].pop_back();
			}
		}
		int max = 0;
		for (int i = 1; i <= N; i++) {
			if (time[i] > max) {
				max = time[i];
			}
		}
		cout << max << '\n';

	}
	return 0;
}