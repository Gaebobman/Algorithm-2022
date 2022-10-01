#include <iostream>
#include <vector>

using namespace std;
bool end_flag = false;
int post_infection(const int m, const int my_self, const int parent, vector<int>& visited, vector<int>& infected, vector<vector<int>>& graph) {
	visited[my_self] = 1;
	int sum = infected[my_self];
	// 자기 자신과 연결된 vertex들을 순회 (자식 방문)
	for (int i = 0; i < graph[my_self].size(); i++) {
		if (visited[graph[my_self][i]] == 0 && end_flag == false) {

			sum += post_infection(m, graph[my_self][i], my_self, visited, infected, graph);
			if (end_flag == true) {
				cout << min(my_self, graph[my_self][i]) << ' ' << max(my_self, graph[my_self][i]) << '\n';
			}
			if (sum == m && end_flag == false) {
				if (my_self == 1) {
					if (m == 1) {
						end_flag = true;
					}
				}
				else {
					end_flag = true;
				}
				
			}
		}

	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0, n = 0, m = 0;

	cin >> T;

	while (T--) {

		int x, y;
		cin >> n >> m;
		vector<int> visited(n + 1, 0);
		vector<int> infected(n + 1, 0);
		vector<vector<int>> graph(n + 1);

		for (int i = 0; i < n - 1; i++) {
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for (int i = 0; i < m; i++) {
			cin >> x;
			infected[x] = 1;
		}
		post_infection(m, 1, 1, visited, infected, graph);
		if (end_flag == false) {
			cout << -1 << '\n';
		}
		else {
			end_flag = false;
		}

	}
	return 0;
}