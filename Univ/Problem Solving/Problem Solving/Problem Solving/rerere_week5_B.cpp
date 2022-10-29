#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M, y, t;
		string s1, s2;
		cin >> N >> M;
		vector<pair<int, string >> city_with_year;
		map<string, pair<int, int>> index_of_city_year;
		vector<pair<int,int>>* G = new vector<pair<int, int>>[N + 1]; // [from][{to, time}]
		int* time = new int[N + 1];
		memset(time, 0, (N + 1) * sizeof(int));

		for (int i = 0; i < N; i++) {
			cin >> s1 >> y;
			city_with_year.push_back({ y, s1 });
			index_of_city_year.insert({ s1, {i, y }});
		}
		sort(city_with_year.begin(), city_with_year.end());
		for (int i = 0; i < M; i++) {
			cin >> s1 >> s2 >> t;
			int s1_idx = index_of_city_year[s1].first;
			int s2_idx = index_of_city_year[s2].first;
			int s1_year = index_of_city_year[s1].second;
			int s2_year = index_of_city_year[s2].second;

			
			if (s1_year > s2_year) {
				G[s2_idx].push_back({ s1_idx, t});
			}
			else if (s1_year < s2_year){
				G[s1_idx].push_back({ s2_idx, t});
			}
		}
		for (int i = 0; i < N; i++) {
			string current_city = city_with_year[i].second;
			int current_idx = index_of_city_year[current_city].first;
			for (int j = 0; j < G[current_idx].size(); j++) {
				int dest = G[current_idx][j].first;
				int time_to_dest = G[current_idx][j].second;
				time[dest] = max(time[dest], time[current_idx] + time_to_dest);
			}
		}
		int result = time[0];
		for (int i = 1; i < N; i++) {
			if (time[i] > result)
				result = time[i];
		}
		cout << result << '\n';
		G->clear();
		delete[] time;
	}
	return 0;
}