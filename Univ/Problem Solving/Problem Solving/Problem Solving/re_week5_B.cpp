#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
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
		vector<vector<pair<int, int>>> G(N);	// 그래프
		vector<int> year_of_index(N);		// 인덱스에 해당하는 도시의 연도
		int* indegree;
		int* visited;
		int* time;
		memset(&indegree, 0, N);
		memset(&visited, 0, N);
		memset(&time, 0, N);

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

		// 2. 버스 정보를 입력받는다. (DAG + 같은 연도에서 같은 연도로 이동 불가)
		for (int i = 0; i < M; i++) {
			cin >> s1 >> s2>> t;
			int s1_key = index_of_city.find(s1)->second;
			int s2_key = index_of_city.find(s2)->second;
			// 같은 연도에서 같은 연도로 가는 간선을 만들지 않기 위함
			if (year_of_index[s1_key] != year_of_index[s2_key]) {
				G[min(s1_key, s2_key)].push_back({ max(s1_key, s2_key), t });
				indegree[max(s1_key, s2_key)]++;
			}
		}
		for (int i = 0; i < N; i++) {
			if (indegree[i] == 0) {
				Q.push(i);
				visited[i] = 1;
			}
		}
		while (!Q.empty()) {
			int first = Q.front(); Q.pop();
		}




		free(indegree);
		free(visited);
		free(time);
	}

	return 0;
}