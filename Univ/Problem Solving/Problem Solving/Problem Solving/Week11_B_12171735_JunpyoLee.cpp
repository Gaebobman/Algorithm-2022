// WRONG
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool is_first(int score_board[], int m);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m, tmp;
		queue<int> inha_player;		// 인하팀 선수의 위치를 저장
		cin >> n >> m;
		int* table = new int[n + 1]();
		int* score_board = new int[m + 1]();
		int* visited = new int[n + 1]();
		int current_score = n;
		int game_played = 0;
		bool is_first_place = false;
		// Inha == 1; a = 2, b = 3, c, d ....
		for (int i = 1; i < n + 1; i++) {
			cin >> tmp;
			table[i] = tmp;
			score_board[tmp] += current_score--;
			// if current player is from inha
			if (tmp == 1) 
				inha_player.push(i);
		}
		inha_player.pop();
		// 시작부터 1등인지?
		is_first_place = is_first(score_board, m);
		while (inha_player.size() && !is_first_place) {
			int current_player = inha_player.front();
			int opponent = table[current_player - 1];
			inha_player.pop();
			// 앞 선수가 인하팀 선수 아니면
			if (opponent != 1 && visited[opponent] == 0) {
				score_board[opponent]--;
				score_board[1]++;
				// And swap place
				//table[current_player - 1] = 1;
				//table[current_player] = opponent;
				visited[current_player - 1] = 1;
				visited[current_player] = 1;
				game_played++;
				// Check if Inha is first place
				if (is_first(score_board, m)) {
					is_first_place = true;
					break;
				}
			}
		}
		if (is_first_place)
			cout << game_played << '\n';
		else
			cout << "-1\n";
		delete[] table;
		delete[] score_board;
	}

	return 0;
}

bool is_first(int score_board[], int m) {
	int inha_score = score_board[1];
	for (int i = 2; i <= m; i++) {
		if (inha_score <= score_board[i]) 
			return false;
	}
	return true;
}