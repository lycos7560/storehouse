#include <iostream>
#include <queue>

using namespace std;

// N ����, M ����
int N, M, dx, dy, maxCnt = 0;

// N, M�� ���� 
int map[1000][1000];
bool mapCheck[1000][1000];

// Ž���ϴ� ���� ���� =>  ��, �� ,�� ,��
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

queue<pair<int, int>> myQueue;

pair<int, int> tempPair;

bool falseCheck = true;

// ����� �ڵ�
bool debug = true;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
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
			if (map[i][j] == 1) { // ���� �丶�並 ť�� �ְ� �湮ó��
				mapCheck[i][j] = true;
				map[i][j] = 0; // map[i][j] = ���� ��¥
				myQueue.push(make_pair(i, j));
			}
		}
	}

	while (!myQueue.empty()) {

		tempPair = myQueue.front();
		myQueue.pop();

		// ��/��/��/�츦 Ž���ϱ� ���� �ݺ���
		for (int i = 0; i < 4; i++) {
			dx = tempPair.first + dxdy[i][0];
			dy = tempPair.second + dxdy[i][1];

			// ������ ������ ����� ��� => �Ѿ��.
			if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			// '-1' �� ���, �̹� �湮�� �� �� ��� => �Ѿ��.
			if (mapCheck[dx][dy] == true || map[dx][dy] == -1) continue;

			map[dx][dy] = map[tempPair.first][tempPair.second] + 1; // ī��Ʈ�� �÷��ش�.
			mapCheck[dx][dy] = true; // �湮ó��
			myQueue.push(make_pair(dx, dy));
		}
	}


	for (int i = 0; i < N && falseCheck; i++) {
		for (int j = 0; j < M && falseCheck; j++) {

			maxCnt = max(maxCnt, map[i][j]); // ��¥ ���

			// ���� ���� �丶�䰡 �湮ó���� �ȵǾ��ִٸ� �����ִٴ� �� 
			if (map[i][j] == 0 && mapCheck[i][j] == false)  falseCheck = false;
		}
	}

	// ���� ���� �丶�䰡 �ִٸ� -1 ���
	// ���ٸ� ��¥ ���
	if (falseCheck) cout << maxCnt; 
	else cout << -1;


	if (debug) {

		cout << "\n";
		for (int i = 0; i < N; i++) {  // ����׿� �ڵ�(�湮)
			for (int j = 0; j < M; j++) {
				cout << mapCheck[i][j] << " ";
			}
			cout << "\n";
		}

		cout << "\n";
		for (int i = 0; i < N; i++) { // ����׿� �ڵ�(ī��Ʈ)
			for (int j = 0; j < M; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}