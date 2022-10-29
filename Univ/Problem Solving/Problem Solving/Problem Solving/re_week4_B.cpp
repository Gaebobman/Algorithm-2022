#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

pair<int, int> answer = { 0, 0 };

int dfs(int n, vector<int> graph[] , int visited[], int infected[], int m)
{
	int infection_count = 0;
	if (infected[n]) {
		infection_count = 1;
	}
	visited[n] = 1;
	for (int i = 0; i < graph[n].size(); i++)
	{
		if (!visited[graph[n][i]]) {
			infection_count += dfs(graph[n][i], graph, visited, infected, m);
		}
	}

	if (infection_count == m) {
		if (answer.second == 0) {
			answer.second = n;
		}
		else if (answer.first == 0) {
			answer.first = n;
		}
	}

	return infection_count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n, m, u, v;
		cin >> n >> m;
		vector<int> *G = new vector<int>[n + 1];
		int* visited = new int[n + 1];
		int* infected = new int[n + 1];
		memset(visited, 0, (n + 1) * sizeof(int));
		memset(infected, 0, (n + 1) * sizeof(int));

		for (int j = 0; j < n - 1; j++)
		{
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		for (int j = 0; j < m; j++)
		{
			cin >> u;
			infected[u] = 1;
		}

		int count = dfs(1, G, visited, infected, m);

		if (answer.second == 1) {
			cout << -1 << "\n";
		}
		else {
			if (answer.first > answer.second)
				cout << answer.second << " " << answer.first << "\n";
			else
				cout << answer.first << " " << answer.second << "\n";
		}

		answer = { 0, 0 };
		delete[] visited;
		delete[] infected;
		G->clear();

	}
	return 0;
}