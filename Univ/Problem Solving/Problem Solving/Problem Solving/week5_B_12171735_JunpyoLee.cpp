#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second > b.second;
}

int travel(const map<string, pair<string, int>> bus,
	vector<pair<string, int>> date,
	int dp[],
	string start)
{
	// 1. ������ �����������θ� �̵� ����, �뼱���� �̵����� �Ѱ͵��� Ȯ��
	for (int i = 0; i < bus.size(); i++) {

	}



}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T;
	cin >> T;
	int N, M, time;
	string name, stt, dst;
	int year;
	while (T--) {
		int key = 0;
		cin >> N >> M;
		int* dp;
		memset(&dp, 0, N);
		map<string, int> date;
		map<string, pair<string, int>> bus;
		for (int i = 0; i < N; i++) {
			cin >> name >> year;
			date.insert(make_pair(name, year));
		}
		// ��¥������ �������� ����
		sort(date.begin(), date.end(), compare);

		for (int i = 0; i < M; i++) {
			cin >> stt >> dst >> time;
			if (date[stt] < date[dst]) {
				bus.insert_or_assign(stt, make_pair(dst, time));
			}
		}
		cout << bus[stt].first;
		// ��� ������ ���������� �湮�� ���, 
		// DP ���̺��� �ش� ���������� �ִ� �׻�����
		for (int i = 0; i < N; i++) {
			//date[i].first;
		}

	}
	return 0;
}