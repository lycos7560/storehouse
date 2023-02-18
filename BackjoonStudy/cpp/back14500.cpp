#include <iostream>

using namespace std;

constexpr int MAX = 500;

int map[MAX][MAX];

bool checkMap[MAX][MAX];

int N, M, result = 0;

// 탐색하는 방향 설정 =>  상, 하 ,좌 ,우
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void DFS_Search(int nowX, int nowY, int cnt, int val)
{
	if (cnt == 4) {
		result = max(result, val);
		return;
	}

	for (int i = 0; i < 4; i++) {

		int dx = nowX + dxdy[i][0];
		int dy = nowY + dxdy[i][1];

		// 범위를 벗어나면 넘어간다.
		if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
		// 방문했다면 넘어간다.
		if (checkMap[dx][dy] == true) continue;

		cnt++;
		val += map[dx][dy];
		checkMap[dx][dy] = true;
		DFS_Search(dx, dy, cnt, val);
		checkMap[dx][dy] = false;
		cnt--;
		val -= map[dx][dy];

	}
}

// 'ㅗ' 탐색을 위한 함수
void Exception_Search(int nowX, int nowY, int val)
{
	for (int i = 0; i < 4; i++) {
		int dx = nowX + dxdy[i][0];
		int dy = nowY + dxdy[i][1];
		if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
		val += map[dx][dy];
	}

	for (int i = 0; i < 4; i++) {
		int dx = nowX + dxdy[i][0];
		int dy = nowY + dxdy[i][1];

		if (dx < 0 || dy < 0 || dx >= N || dy >= M) {
			result = max(result, val);
			continue;
		}

		val -= map[dx][dy];
		result = max(result, val);
		val += map[dx][dy];
	}

}


int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			checkMap[i][j] = true;
			DFS_Search(i, j, 1, map[i][j]);
			checkMap[i][j] = false;
			Exception_Search(i, j, map[i][j]);
		}
	}

	cout << result;

	return 0;
}