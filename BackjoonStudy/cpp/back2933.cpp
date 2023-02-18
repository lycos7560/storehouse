#include <iostream>
#include <list>
#include <queue>

using namespace std;

// RC의 범위 최대값
constexpr int MAX = 101;

// 기본 맵
char map[MAX][MAX];

// 방문처리 
bool mapCheck[MAX][MAX];

// BFS 사용할 Q
queue<pair<int, int>> myQ;

pair<int, int> tempP;

// R 행, C 열, N 막대기를 던진 횟수
int R, C, N;

int dx, dy, dis;

int temp = 0;

// 탐색하는 방향 설정 =>  상, 하 ,좌 ,우
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };


list<int> myList;
list<int>::iterator it;

list<pair<int, int>> cList;
list<pair<int, int>>::iterator cit;

// true = left, false = right
bool check = false, leftRight = false;

void BFS(int x, int y)
{
	myQ.push(make_pair(x, y));

	while (!myQ.empty()) {
		tempP = myQ.front();
		myQ.pop();

		for (int i = 0; i < 4; i++) {
			dy = tempP.second + dxdy[i][1];
			dx = tempP.first + dxdy[i][0];
			// 문제의 범위를 벗어나는 경우 => 넘어간다.
			if (dx <= 0 || dy <= 0 || dy > C || dx > R) continue;
			// 방문 처리가 되었거나 빈공간 => 넘어간다.
			if (mapCheck[dx][dy] == true || map[dx][dy] == '.') continue;
			mapCheck[dx][dy] = true;
			myQ.push(make_pair(dx, dy));
		}
	}
}

void CheckFloor() // 바닥을 체크합니다.
{
	for (int y = 1; y <= C; y++) {
		// 바닥에 클러스터가 발견되고 방문처리가 되지 않았다면 
		if (map[1][y] == 'x' && mapCheck[1][y] == false) {
			BFS(1, y); // BFS로 마킹
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	// 처음 맵을 초기화 해준다.
	for (int x = 1; x < MAX; x++) {
		for (int y = 1; y < MAX; y++) {
			map[x][y] = '.';
		}
	}

	cin >> R >> C;

	// 미네랄의 위치를 설정 (아래서 부터 시작)
	for (int x = R; x >= 1; x--) {
		for (int y = 1; y <= C; y++) {
			cin >> map[x][y];
		}
	}

	cin >> N;

	/// 던진 횟수와 높이를 설정
	while (N > 0) {
		cin >> temp;
		myList.push_back(temp);
		N--;
	}

	// 던진 막대기 리스트를 순회합니다.
	for (it = myList.begin(); it != myList.end(); it++) {

		check = false; // 미네랄 부셔짐 체크 해제
		cList.clear(); // 공중의 미네랄 리스트 초기화

		// 해당 위치에 미네랄이 있는지 검색합니다.
		if (leftRight) { // 좌측 검색
			for (int y = C; y >= 1; y--) {
				// 만약 미네랄이 있다면
				if (map[*it][y] == 'x') {
					// 해당 미네랄을 빈 공간으로 만든다.
					map[*it][y] = '.';
					// 바닥과 연결된 모든 클러스터를 방문처리
					CheckFloor();
					check = true;
					break;
				}
			}

			leftRight = !leftRight;
		}
		else { // 우측 검색
			for (int y = 1; y <= C; y++) {
				// 만약 미네랄이 있다면
				if (map[*it][y] == 'x') {
					// 해당 미네랄을 빈 공간으로 만든다.
					map[*it][y] = '.';
					// 바닥과 연결된 모든 클러스터를 방문처리
					CheckFloor();
					check = true;
					break;
				}
			}

			leftRight = !leftRight;
		}

		if (check) {  // 미네랄이 부셔졌다면
			// 공중에 있는 클러스트들을 리스트에 담는다.
			for (int x = R; x >= 1; x--) {
				for (int y = C; y >= 1; y--) {
					if (map[x][y] == 'x' && mapCheck[x][y] == false) {
						cList.push_back(make_pair(x, y));
					}
				}
			}

			// 공중에 미네랄이 바닥과 연결될때까지 반복
			dis = 1;
			bool floor = true;
			while (floor) {

				if (cList.size() == 0) break;

				for (cit = cList.begin(); cit != cList.end(); cit++) {
					tempP.first = cit->first;
					tempP.second = cit->second;

					if (mapCheck[tempP.first - (dis + 1)][tempP.second] == true || tempP.first - (dis + 1) == 0) {
						floor = false;
						break;
					}
				}

				dis++;
			}

			if (!floor) {
				for (cit = cList.begin(); cit != cList.end(); cit++) {
					tempP.first = cit->first;
					tempP.second = cit->second;
					map[tempP.first][tempP.second] = '.';
				}

				for (cit = cList.begin(); cit != cList.end(); cit++) {
					tempP.first = cit->first;
					tempP.second = cit->second;
					map[tempP.first - (dis - 1)][tempP.second] = 'x';
				}	
			}

			// 방문 처리를 초기화 
			for (int x = R; x >= 1; x--) {
				for (int y = 1; y <= C; y++) {
					mapCheck[x][y] = false;
				}
			}
		}
	}

	for (int x = R; x >= 1; x--) {
		for (int y = 1; y <= C; y++) {
			cout << map[x][y];
		}
		if (x == 1) break;
		cout << "\n";
	}

	return 0;

}
