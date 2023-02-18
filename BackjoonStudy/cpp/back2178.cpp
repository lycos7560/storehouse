#include <iostream>
#include <queue>

using namespace std;

string str;

int N, M, dx, dy;

// 처음 방문시에는 갈 수 있는지 없는지 확인(0, 1)
// 방문한 다음에는 몇번쨰로 방문 했는지 기록
int map[101][101];

// 해당 좌표에 방문을 했는지 체크
bool checkMap[101][101];

// 탐색하는 방향 설정 =>  상, 하 ,좌 ,우
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// BFS를 위한 Queue
queue<pair<int, int>> myQueue;

pair<int, int> tempPair;

// 디버그용 bool
bool debug = true;

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {

		cin >> str; // 입력을 문자열 자체로 받음

		// string 의 인덱스를 이용하여 map에 마킹
		// char -> int
		for (int j = 0; j < M; j++) map[i][j + 1] = str[j] - '0';
	}


	// BFS를 시작하기위한 초기값 설정
	checkMap[1][1] = true;
	map[1][1] = 1; // 카운트
	myQueue.push(make_pair(1, 1));

	while (!myQueue.empty()) {

		tempPair = myQueue.front();
		myQueue.pop();

		// 상/하/좌/우를 탐색하기 위한 반복문
		for (int i = 0; i < 4; i++) {

			dx = tempPair.first + dxdy[i][0];
			dy = tempPair.second + dxdy[i][1];

			// 문제의 범위를 벗어나는 경우 => 넘어간다.
			if (dx == 0 || dy == 0 || dx > N || dy > M) continue;

			// '0' 이동할 수 없는 칸 인 경우, 이미 방문한 곳 일 경우 => 넘어간다.
			if (map[dx][dy] == 0 || checkMap[dx][dy] == true) continue;

			map[dx][dy] = map[tempPair.first][tempPair.second] + 1; // 카운트를 올려준다.
			checkMap[dx][dy] = true; // 방문처리
			myQueue.push(make_pair(dx, dy));

			if (dx == N && dy == M) { // 목적지에 도달했다면 중지

				// 외부 	while (!myQueue.empty())을 나가기 위해서
				// Queue를 비워준다.
				while (!myQueue.empty()) myQueue.pop(); 

				break;
			}
		}
	}

	// 정답 출력(해당 위치에 도달하기위한 최소)
	cout << map[N][M];



	if (debug) { // 시각적 디버그용 코드
		cout << "\n";
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
	}



	return 0;
}