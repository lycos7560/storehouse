#include <iostream>
#include <list>
#include <queue>

using namespace std;

// RC�� ���� �ִ밪
constexpr int MAX = 101;

// �⺻ ��
char map[MAX][MAX];

// �湮ó�� 
bool mapCheck[MAX][MAX];

// BFS ����� Q
queue<pair<int, int>> myQ;

pair<int, int> tempP;

// R ��, C ��, N ����⸦ ���� Ƚ��
int R, C, N;

int dx, dy, dis;

int temp = 0;

// Ž���ϴ� ���� ���� =>  ��, �� ,�� ,��
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
			// ������ ������ ����� ��� => �Ѿ��.
			if (dx <= 0 || dy <= 0 || dy > C || dx > R) continue;
			// �湮 ó���� �Ǿ��ų� ����� => �Ѿ��.
			if (mapCheck[dx][dy] == true || map[dx][dy] == '.') continue;
			mapCheck[dx][dy] = true;
			myQ.push(make_pair(dx, dy));
		}
	}
}

void CheckFloor() // �ٴ��� üũ�մϴ�.
{
	for (int y = 1; y <= C; y++) {
		// �ٴڿ� Ŭ�����Ͱ� �߰ߵǰ� �湮ó���� ���� �ʾҴٸ� 
		if (map[1][y] == 'x' && mapCheck[1][y] == false) {
			BFS(1, y); // BFS�� ��ŷ
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	// ó�� ���� �ʱ�ȭ ���ش�.
	for (int x = 1; x < MAX; x++) {
		for (int y = 1; y < MAX; y++) {
			map[x][y] = '.';
		}
	}

	cin >> R >> C;

	// �̳׶��� ��ġ�� ���� (�Ʒ��� ���� ����)
	for (int x = R; x >= 1; x--) {
		for (int y = 1; y <= C; y++) {
			cin >> map[x][y];
		}
	}

	cin >> N;

	/// ���� Ƚ���� ���̸� ����
	while (N > 0) {
		cin >> temp;
		myList.push_back(temp);
		N--;
	}

	// ���� ����� ����Ʈ�� ��ȸ�մϴ�.
	for (it = myList.begin(); it != myList.end(); it++) {

		check = false; // �̳׶� �μ��� üũ ����
		cList.clear(); // ������ �̳׶� ����Ʈ �ʱ�ȭ

		// �ش� ��ġ�� �̳׶��� �ִ��� �˻��մϴ�.
		if (leftRight) { // ���� �˻�
			for (int y = C; y >= 1; y--) {
				// ���� �̳׶��� �ִٸ�
				if (map[*it][y] == 'x') {
					// �ش� �̳׶��� �� �������� �����.
					map[*it][y] = '.';
					// �ٴڰ� ����� ��� Ŭ�����͸� �湮ó��
					CheckFloor();
					check = true;
					break;
				}
			}

			leftRight = !leftRight;
		}
		else { // ���� �˻�
			for (int y = 1; y <= C; y++) {
				// ���� �̳׶��� �ִٸ�
				if (map[*it][y] == 'x') {
					// �ش� �̳׶��� �� �������� �����.
					map[*it][y] = '.';
					// �ٴڰ� ����� ��� Ŭ�����͸� �湮ó��
					CheckFloor();
					check = true;
					break;
				}
			}

			leftRight = !leftRight;
		}

		if (check) {  // �̳׶��� �μ����ٸ�
			// ���߿� �ִ� Ŭ����Ʈ���� ����Ʈ�� ��´�.
			for (int x = R; x >= 1; x--) {
				for (int y = C; y >= 1; y--) {
					if (map[x][y] == 'x' && mapCheck[x][y] == false) {
						cList.push_back(make_pair(x, y));
					}
				}
			}

			// ���߿� �̳׶��� �ٴڰ� ����ɶ����� �ݺ�
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

			// �湮 ó���� �ʱ�ȭ 
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
