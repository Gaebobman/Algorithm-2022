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
		queue<int> Q;	// Topological sort �� ���� Queue
		string s, s1, s2;
		vector<pair<string, int>> city_with_year;	// ���ÿ� ������ ����
		map<string, int> index_of_city;		// ���ø� �ε����� ����
		cin >> N >> M;
		vector<vector<pair<int, int>>> G(N);	// �׷���
		vector<int> year_of_index(N);		// �ε����� �ش��ϴ� ������ ����
		int* indegree;
		int* visited;
		int* time;
		memset(&indegree, 0, N);
		memset(&visited, 0, N);
		memset(&time, 0, N);

		// 1. ���ÿ� ������ �Է¹޴´�
		for (int i = 0; i < N; i++) {
			cin >> s >> y;
			city_with_year.push_back({ s, y });
		}
		// �湮������ ������������ ���ĵ�.
		sort(city_with_year.begin(), city_with_year.end(), compare);

		// ���ÿ� INDEX �ο� / �ε����� ������ �����ϱ� ���� ����
		for (int i = 0; i < N; i++) {
			index_of_city.insert({ city_with_year[i].first, i });
			year_of_index[i] = city_with_year[i].second;
		}

		// 2. ���� ������ �Է¹޴´�. (DAG + ���� �������� ���� ������ �̵� �Ұ�)
		for (int i = 0; i < M; i++) {
			cin >> s1 >> s2>> t;
			int s1_key = index_of_city.find(s1)->second;
			int s2_key = index_of_city.find(s2)->second;
			// ���� �������� ���� ������ ���� ������ ������ �ʱ� ����
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