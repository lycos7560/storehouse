#include <iostream>
#include <queue>

using namespace std;

string str;

int N, M, dx, dy;

// ó�� �湮�ÿ��� �� �� �ִ��� ������ Ȯ��(0, 1)
// �湮�� �������� ������� �湮 �ߴ��� ���
int map[101][101];

// �ش� ��ǥ�� �湮�� �ߴ��� üũ
bool checkMap[101][101];

// Ž���ϴ� ���� ���� =>  ��, �� ,�� ,��
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// BFS�� ���� Queue
queue<pair<int, int>> myQueue;

pair<int, int> tempPair;

// ����׿� bool
bool debug = true;

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {

		cin >> str; // �Է��� ���ڿ� ��ü�� ����

		// string �� �ε����� �̿��Ͽ� map�� ��ŷ
		// char -> int
		for (int j = 0; j < M; j++) map[i][j + 1] = str[j] - '0';
	}


	// BFS�� �����ϱ����� �ʱⰪ ����
	checkMap[1][1] = true;
	map[1][1] = 1; // ī��Ʈ
	myQueue.push(make_pair(1, 1));

	while (!myQueue.empty()) {

		tempPair = myQueue.front();
		myQueue.pop();

		// ��/��/��/�츦 Ž���ϱ� ���� �ݺ���
		for (int i = 0; i < 4; i++) {

			dx = tempPair.first + dxdy[i][0];
			dy = tempPair.second + dxdy[i][1];

			// ������ ������ ����� ��� => �Ѿ��.
			if (dx == 0 || dy == 0 || dx > N || dy > M) continue;

			// '0' �̵��� �� ���� ĭ �� ���, �̹� �湮�� �� �� ��� => �Ѿ��.
			if (map[dx][dy] == 0 || checkMap[dx][dy] == true) continue;

			map[dx][dy] = map[tempPair.first][tempPair.second] + 1; // ī��Ʈ�� �÷��ش�.
			checkMap[dx][dy] = true; // �湮ó��
			myQueue.push(make_pair(dx, dy));

			if (dx == N && dy == M) { // �������� �����ߴٸ� ����

				// �ܺ� 	while (!myQueue.empty())�� ������ ���ؼ�
				// Queue�� ����ش�.
				while (!myQueue.empty()) myQueue.pop(); 

				break;
			}
		}
	}

	// ���� ���(�ش� ��ġ�� �����ϱ����� �ּ�)
	cout << map[N][M];



	if (debug) { // �ð��� ����׿� �ڵ�
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