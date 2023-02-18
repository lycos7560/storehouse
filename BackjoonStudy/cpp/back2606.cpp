#include <iostream>
#include <queue>

using namespace std;

// 컴퓨터의 수 N, 연결수 K
int N, K, B, cnt = 0;

queue<int> myQueue;

pair<int, int> temp;

// 연결을 나타낸다.
bool connect[101][101];

// 컴퓨터의 감염 유무
bool computer[101];


int main()
{
	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		cin >> temp.first >> temp.second;
		// 양방향으로 연결
		connect[temp.first][temp.second] = true;
		connect[temp.second][temp.first] = true;
	}
	
	// 1번 컴퓨터를 감염시키고
	computer[1] = true;
	myQueue.push(1); // 큐에 넣어준다.

	// BFS 탐색 시작
	while (!myQueue.empty()) {

		B = myQueue.front();
		myQueue.pop();

		for (int i = 1; i <= N; i++) {

			// 컴퓨터가 연결이 되지 않았다. => 넘어간다.
			if (connect[B][i] == false && connect[i][B] == false) continue;
			else if (computer[i] == true) continue; 
			// 이미 감염이 되어있다. => 넘어간다.

			// 해당 컴퓨터를 감염시키고
			computer[i] = true;
			cnt++; // 감염된 카운트를 올려준다.
			myQueue.push(i); // 큐에 넣어준다.
		}
	}

	cout << cnt;

	return 0;
}