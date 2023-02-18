#include <iostream>
#include <queue>

using namespace std;

constexpr auto MAX = 100;

// ���� 0 - 99
// 0�� �����
// 2 ��
// 1 ���
int map[MAX][MAX];
int mapN;
int timeCnt;

// ���� ��ġ�� ����
queue<pair<int, int>> snakeQueue;

// ���� �̵� �ð� �� �ൿ�� ����
// X�� 10, 000 ������ ���� ����
char snakeMoveArr[10000];
// ���� �Ӹ���ġ
pair<int, int> snakeHead;
// ���� �Ӹ� ����
int snakeDir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

pair<int, int> tempPair;

bool debug = false;

// �ð��� ����� Ȯ�ο�
void DebugPrint()
{
	for (int i = 0; i < mapN; i++)
	{
		for (int j = 0; j < mapN; j++)
		{
			cout << map[i][j] << " ";
		}

		cout << "\n";
	}
}

// ���� �ʱ�ȭ �մϴ�.
void Initialization()
{
	cin >> mapN;
	timeCnt = 0;

	// ���� �ൿ�� �������� �ʱ�ȭ
	for (int i = 0; i < 10000; i++)
	{
		snakeMoveArr[i] = 'F';
	}

	// ���� �Ӹ��� ��ġ�� �ʱ�ȭ
	snakeHead.first = 0;
	snakeHead.second = 0;

	// ���� �ʱ�ȭ
	for (int i = 0; i < mapN; i++)
	{
		for (int j = 0; j < mapN; j++)
		{
			map[i][j] = 0;
		}
	}
}

// �ʿ� ����� ��ġ�մϴ�.
void GetInput()
{
	int appleCnt = 0;
	cin >> appleCnt;

	while (appleCnt > 0)
	{
		cin >> tempPair.first >> tempPair.second;
		map[tempPair.first -1 ][tempPair.second -1] =  1;
		appleCnt--;
	}

	int snakeMoveCnt = 0;
	cin >> snakeMoveCnt;
	int tempInt;
	char tempChar;

	while (snakeMoveCnt > 0)
	{
		cin >> tempInt >> tempChar;
		snakeMoveArr[tempInt] = tempChar;
		snakeMoveCnt--;
	}
}

// ������ �����մϴ�.
void StartGame(int x, int y)
{
	tempPair.first = x;
	tempPair.second = y;
	snakeQueue.push(tempPair);
	map[x][y] = 2;
	int dir = 0;
	bool snakeDie = false;

	// ���� ���� �ʾ��� ��� ��� �ݺ�
	for (int i = 0; !snakeDie && i < 10000; i++)
	{
		timeCnt++;

		switch (snakeMoveArr[i])
		{
			case 'F':
				snakeHead.first += snakeDir[dir][0];
				snakeHead.second += snakeDir[dir][1];
				break;

			case 'D':
				dir++;
				if (dir >= 4){ dir = 0; }
				snakeHead.first += snakeDir[dir][0];
				snakeHead.second += snakeDir[dir][1];
				break;

			case 'L':
				dir--;
				if (dir <= -1) { dir = 3; }
				snakeHead.first += snakeDir[dir][0];
				snakeHead.second += snakeDir[dir][1];
				break;

			default:
				cout << "i  : " << i << " snakeMoveArr[i] :" << snakeMoveArr[i] << "�̰� �߸� ����";
				break;
		}
		
		// ���� ���� �Ӹ��� ������ ����ų� �ڽ��� ���� �ε����� �� 
		// 10000���� �ѱ� ���
		if (snakeHead.first <= -1 || snakeHead.first >= mapN || 
			snakeHead.second <= -1 || snakeHead.second >= mapN || 
			map[snakeHead.first][snakeHead.second] == 2 )
		{
			snakeDie = true;
			continue;
		}

		// ���� ���� �Ӹ��� ����� ��ġ�� ���
		if (map[snakeHead.first][snakeHead.second] == 1)
		{   
			// �ʿ��� �ش� ��ġ�� ������ ��ŷ�ϰ� ť�� ���� 
			map[snakeHead.first][snakeHead.second] = 2;
			snakeQueue.push(make_pair(snakeHead.first, snakeHead.second));
		}
		else // �ƴҰ�� �����
		{
			// �ʿ��� �ش� ��ġ�� ������ ��ŷ�ϰ� ť�� ���� 
			map[snakeHead.first][snakeHead.second] = 2;
			snakeQueue.push(make_pair(snakeHead.first, snakeHead.second));
			// ������ �ϳ� ���ش�.(�̵�)
			tempPair.first = snakeQueue.front().first;
			tempPair.second = snakeQueue.front().second;
			map[tempPair.first][tempPair.second] = 0;
			snakeQueue.pop();
		}
	}
}

int main()
{
	Initialization();
	GetInput();
	StartGame(0, 0);

	//�ð��� Ȯ�ο�
	if (debug) { DebugPrint(); }

	cout << timeCnt;

	return 0;
}