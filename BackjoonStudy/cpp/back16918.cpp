#include <iostream>
#include <list>

using namespace std;

// R, C, N �� �ִ밪 ��ũ��
constexpr auto MAX = 200;

// ������ ����
// ���� 0 ~ 199
char map[MAX][MAX];

// ����׿�
bool debug = true;

int R, C, N;

// ���� �ð��� ī��Ʈ
int timeCnt;

// ������ ��ź�� ��ġ�� ������ ����Ʈ
list<pair<int, int>> locationBombList;
list<pair<int, int>>::iterator iterListBomb;

// ��ź�� ������ ���� ����
int dirExplosion[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };


// �ð����� Ȯ���ϱ� ����
void DebugPrint()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j]; //<< " ";
		}

		cout << "\n";
	}
}

// �ʱ�ȭ�� �ϴ� �Լ�
void Initialization()
{
	// �ð� �ʱ�ȭ
	timeCnt = 0;

	// ��� ��ĭ���� �ʱ�ȭ
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			map[i][j] = '.';
		}
	}
}

// �Է��� �޴� �Լ�
void GetInput()
{
	cin >> R >> C >> N;

	// �ʱ� �� �Է¹ޱ�
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}
}



// ������ ��ź�� ����Ʈ�� �ۼ��մϴ�.
void CreateBombList()
{
	// ����Ʈ�� �ʱ�ȭ
	locationBombList.clear();

	// ������ ���� ������ ��ź�� ã�Ƽ� ����Ʈ�� �߰��մϴ�.
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'O')
			{
				locationBombList.push_back(make_pair(i, j));
			}
		}
	}
}

// ������̸� ��ź���� �ٲپ� �ݴϴ�.
void BlankSpaceBombFilling()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == '.')
			{
				map[i][j] = 'O';
			}
		}
	}
}

// ����Ʈ�� ��ź�� ���߽�ŵ�ϴ�.
void bombExplosion()
{
	pair<int, int> tempPair;

	for (iterListBomb = locationBombList.begin(); iterListBomb != locationBombList.end(); iterListBomb++)
	{
		tempPair.first = iterListBomb->first;
		tempPair.second = iterListBomb->second;

		//�ڽ��� ��ġ�� ��������� ����� �ݴϴ�.
		map[tempPair.first][tempPair.second] = '.';

		// ��ź�� �� �� �� �츦 ��������� ����� �ݴϴ�.
		for (int i = 0; i < 4; i++)
		{
			// ���� ������ ����� �ѱ��.
			if (tempPair.first + dirExplosion[i][0] <= -1 || tempPair.first + dirExplosion[i][0] >= R 
				|| tempPair.second + dirExplosion[i][1] <= -1 || tempPair.second + dirExplosion[i][1] >= C)
			{
				continue;
			}

			// �����¿츦 ��������� ������ݴϴ�. (���� ȿ��)
			switch (i)
			{
				case 0:
					map[tempPair.first + dirExplosion[i][0]][tempPair.second + dirExplosion[i][1]] = '.';
					break;

				case 1:

					map[tempPair.first + dirExplosion[i][0]][tempPair.second + dirExplosion[i][1]] = '.';
					break;

				case 2:
					map[tempPair.first + dirExplosion[i][0]][tempPair.second + dirExplosion[i][1]] = '.';
					break;

				case 3:
					map[tempPair.first + dirExplosion[i][0]][tempPair.second + dirExplosion[i][1]] = '.';
					break;
			}

		}
	}
}

// ������ ����
void StartGame()
{
	CreateBombList();
	timeCnt++;
	if (timeCnt == N) { return; }

	BlankSpaceBombFilling();
	timeCnt++;
	if (timeCnt == N) { return; }

	// ���ϴ� �ð��� �ɶ����� ����
	while (true)
	{
		bombExplosion();
		CreateBombList();
		timeCnt++;
		if (timeCnt == N) { break; }

		BlankSpaceBombFilling();
		timeCnt++;
		if (timeCnt == N) { break; }
	}
}

int main()
{
	Initialization();
	GetInput();
	StartGame();

	if (debug) { DebugPrint(); }

	return 0;
}
