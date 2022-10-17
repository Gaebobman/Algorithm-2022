#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, y, t;
		queue<int> Q;	// Topological sort 를 위한 Queue
		string s, s1, s2;
		vector<pair<string, int>> city_with_year;	// 도시와 연도가 저장
		map<string, int> index_of_city;		// 도시를 인덱스로 관리
		cin >> N >> M;
		vector<vector<pair<int, int>>> G(N);	// 그래프 G[start]-{dest, time}
		vector<int> year_of_index(N);		// 인덱스에 해당하는 도시의 연도
		int *indegree = new int[N];
		int* visited = new int[N];
		int* time = new int[N];

		memset(indegree, 0, N * sizeof(int));
		memset(visited, 0, N * sizeof(int));
		memset(time, 0, N * sizeof(int));

		// 1. 도시와 연도를 입력받는다
		for (int i = 0; i < N; i++) {
			cin >> s >> y;
			city_with_year.push_back({ s, y });
		}
		// 방문연도별 오름차순으로 정렬됨.
		sort(city_with_year.begin(), city_with_year.end(), compare);

		// 도시에 INDEX 부여 / 인덱스로 연도를 관리하기 위해 저장
		for (int i = 0; i < N; i++) {
			index_of_city.insert({ city_with_year[i].first, i });
			year_of_index[i] = city_with_year[i].second;
		}

		// 2. 버스 정보를 입력받는다. (DAG / 같은 연도에서 같은 연도로 이동 불가 + 과거로 이동 불가)
		for (int i = 0; i < M; i++) {
			cin >> s1 >> s2>> t;
			int s1_key = index_of_city.find(s1)->second;
			int s2_key = index_of_city.find(s2)->second;
			// cout << "S1: " << s1_key << "S2: " << s2_key << '\n';
			// 같은 연도에서 같은 연도로 가는 간선을 만들지 않기 위함
			if (year_of_index[s1_key] != year_of_index[s2_key]) {
				G[min(s1_key, s2_key)].push_back({ max(s1_key, s2_key), t });
				indegree[max(s1_key, s2_key)]++;
			}
		}
		// 3. 위상정렬 결과를 저장
		vector<int> topology;
		for (int i = 0; i < N; i++) {
			if (indegree[i] == 0) {
				Q.push(i);
				visited[i] = 1;
			}
		}
		while (!Q.empty()) {
			int first = Q.front(); Q.pop();
			topology.push_back(first);
			for (int i = 0; i < G[first].size(); i++) {
				int dest = G[first][i].first;
				if (visited[dest] == 0 && --indegree[dest] == 0) {
					Q.push(dest);
					visited[dest] = 1;
				}
			}
		}

		for (int i = 0; i < topology.size(); i++) {
			for (int j = 0; j < G[topology[i]].size(); j++) {
				int dest = G[topology[i]][j].first;
				int time_to_dest = G[topology[i]][j].second;
				time[dest] = max(time[dest], time[topology[i]] + time_to_dest);
			}
		}
		int result = time[0];
		for (int i = 1; i < N; i++) {
			if (time[i] > result)
				result = time[i];
		}
		cout << result << '\n';
		delete[] indegree; delete[] visited; delete[] time;
		
		
	}

	return 0;
}