// https://www.acmicpc.net/problem/1715
#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue <int, vector<int>, greater<int>> myqueue;		// 카드 덱들의 사이즈를 큐(min heap)에 저장 
	int N, tmp, result;		// input 갯수와, 입력을 받을 임시변수
	result = 0;
	cin >> N;
	while (N--) {
		cin >> tmp;
		myqueue.push(tmp);
	}
	while (myqueue.size() > 1) {
		tmp = myqueue.top();	// 먼저 queue에서 원소(카드 덱) 하나를 뽑음 (그 시점에서 최소임)
		myqueue.pop();
		tmp += myqueue.top();	// queue에서 원소(카드덱)를 더 뽑아서 두 덱을 합침 
		myqueue.pop();
		myqueue.push(tmp);	// 그리고 queue에 삽입함 ( 이전에 없던 덱이 추가된것 과 같음)
		result += tmp;
	}
	cout << result;
	return 0;
}