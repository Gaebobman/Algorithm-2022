#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
bool compare(pair<string, int>& a, pair<string, int>& b) {
	return a.second < b.second;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M, y, t;
		string s1, s2;
		map<string, int> index_of_city;
		vector<pair<string, int>> city_with_year;
		cin >> N >> M;
		vector<int> year_of_index(N + 1);
		vector<pair<int,int>>* G = new vector<pair<int,int>>[N + 1]; // dest, time
		int* indegree = new int[N + 1];
		int* visited = new int[N + 1];
		int* time = new int[N + 1];
		memset(indegree, 0, (N + 1) * sizeof(int));
		memset(visited, 0, (N + 1) * sizeof(int));
		memset(time, 0, (N + 1) * sizeof(int));

		for (int i = 0; i < N; i++) {
			cin >> s1 >> y;
			city_with_year.push_back({ s1, y });
		}
		sort(city_with_year.begin(), city_with_year.end(), compare);

		for (int i = 0; i < N; i++) {
			index_of_city.insert({ city_with_year[i].first, i });
			year_of_index[i] = city_with_year[i].second;
		}

		for (int i = 0; i < M; i++) {
			cin >> s1 >> s2 >> t;
			int s1_idx = index_of_city[s1];
			int s2_idx = index_of_city[s2];
			if (year_of_index[s1_idx] != year_of_index[s2_idx]) {
				G[min(s1_idx, s2_idx)].push_back({ max(s1_idx, s2_idx), t });
			}
		}
		// Topology sort;
		queue<int> Q;
		vector<int>topology;
		for (int i = 0; i < N; i++) {
			if (indegree[i] == 0) {
				Q.push(i);
				visited[i] = 1;
			}
		}
		
		while(!Q.empty()) {
			int node = Q.front(); Q.pop();
			topology.push_back(node);
			for (int i = 0; i < G[node].size(); i++) {
				int dest = G[node][i].first;
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
		for (int i = 0; i < N; i++) {
			if (time[i] > result)
				result = time[i];
		}

		cout << result << '\n';
		delete[] G;
		delete[] indegree;
		delete[] visited;
		delete[] time;
	}
}