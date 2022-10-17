#include <iostream>
#include <vector>
using namespace std;

int a = 0;
int b = 0;
int dfs(int n, vector<int> graph[], int visited[], int injected[], int m)
{
	int count = 0;
	if (injected[n])
	{
		count = 1;
	}
	visited[n] = 1;
	for (int i = 0; i < graph[n].size(); i++)
	{
		if (!visited[graph[n][i]])
		{
			count += dfs(graph[n][i], graph, visited, injected, m);
		}
	}

	if (count == m)
	{
		if (a == 0) {
			a = n;
		}
		else if (b == 0) {
			b = n;
		}
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<int> graph[100001];
		int visited[100001] = {
			0,
		};
		int injected[100001] = {
			0,
		};
		vector<int> answer;

		int n, m, u, v;
		cin >> n >> m;
		for (int j = 0; j < n - 1; j++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int j = 0; j < m; j++)
		{
			cin >> u;
			injected[u] = 1;
		}
		dfs(1, graph, visited, injected, m);


		if (a == 1)
			cout << "-1"
			<< "\n";
		else
		{
			if (a > b)
				cout << b << " " << a << "\n";

			else
				cout << a << " " << b << "\n";
		}

		a = 0;
		b = 0;
	}
}

/*
2
7 2
1 2
1 5
1 7
3 5
5 6
2 4
3 6
4 3
1 2
1 3
1 4
2 3 4
*/