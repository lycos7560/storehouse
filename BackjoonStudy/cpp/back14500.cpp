#include <iostream>

using namespace std;

constexpr int MAX = 500;

int map[MAX][MAX];

bool checkMap[MAX][MAX];

int N, M, result = 0;

// Ž���ϴ� ���� ���� =>  ��, �� ,�� ,��
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

		// ������ ����� �Ѿ��.
		if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
		// �湮�ߴٸ� �Ѿ��.
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

// '��' Ž���� ���� �Լ�
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
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
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