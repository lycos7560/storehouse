#include <iostream>
#include <queue>

using namespace std;

// N 세로, M 가로
int N, M, dx, dy, maxCnt = 0;

// N, M의 범위 
int map[1000][1000];
bool mapCheck[1000][1000];

// 탐색하는 방향 설정 =>  상, 하 ,좌 ,우
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

queue<pair<int, int>> myQueue;

pair<int, int> tempPair;

bool falseCheck = true;

// 디버그 코드
bool debug = true;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) { // 익은 토마토를 큐에 넣고 방문처리
				mapCheck[i][j] = true;
				map[i][j] = 0; // map[i][j] = 익은 날짜
				myQueue.push(make_pair(i, j));
			}
		}
	}

	while (!myQueue.empty()) {

		tempPair = myQueue.front();
		myQueue.pop();

		// 상/하/좌/우를 탐색하기 위한 반복문
		for (int i = 0; i < 4; i++) {
			dx = tempPair.first + dxdy[i][0];
			dy = tempPair.second + dxdy[i][1];

			// 문제의 범위를 벗어나는 경우 => 넘어간다.
			if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			// '-1' 인 경우, 이미 방문한 곳 일 경우 => 넘어간다.
			if (mapCheck[dx][dy] == true || map[dx][dy] == -1) continue;

			map[dx][dy] = map[tempPair.first][tempPair.second] + 1; // 카운트를 올려준다.
			mapCheck[dx][dy] = true; // 방문처리
			myQueue.push(make_pair(dx, dy));
		}
	}


	for (int i = 0; i < N && falseCheck; i++) {
		for (int j = 0; j < M && falseCheck; j++) {

			maxCnt = max(maxCnt, map[i][j]); // 날짜 출력

			// 익지 않은 토마토가 방문처리가 안되어있다면 막혀있다는 뜻 
			if (map[i][j] == 0 && mapCheck[i][j] == false)  falseCheck = false;
		}
	}

	// 익지 않은 토마토가 있다면 -1 출력
	// 없다면 날짜 출력
	if (falseCheck) cout << maxCnt; 
	else cout << -1;


	if (debug) {

		cout << "\n";
		for (int i = 0; i < N; i++) {  // 디버그용 코드(방문)
			for (int j = 0; j < M; j++) {
				cout << mapCheck[i][j] << " ";
			}
			cout << "\n";
		}

		cout << "\n";
		for (int i = 0; i < N; i++) { // 디버그용 코드(카운트)
			for (int j = 0; j < M; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}