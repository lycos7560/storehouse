#include <iostream>

using namespace std;

// ����, ������ ���̴� �ִ�ġ�� 500
constexpr auto MAX = 500;

// 0 �����, 1 ���
int map[MAX][MAX];

// ���� / ����
int H, W, tempOne;

// ù ����� ��ŷ�ϴ� bool ��
bool leftRight;

// ������ ����
int rainwaterCnt;

bool debugbool = false;

// �ð����� ������� ���� �Լ�
void VisualDebug()
{
	cout << "\n";
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

// ������ �Է��� �޴� �Լ�
void ReceiveInput()
{
	cin >> H >> W;

	for (int i = 0; i < W; i++)
	{
		cin >> tempOne;
		for (int j = 0; j < tempOne; j++)
		{
			map[i][j] = 1;
		}
	}
}

// �ʱ�ȭ�� �����ϴ� �Լ�
void Initialization()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			map[i][j] = 0;
		}
	}
}

// ������ ī��Ʈ �մϴ�.
void CountRainwater()
{
	rainwaterCnt = 0;

	// �Ʒ����� ���� �˻�
	for (int i = 0; i < H; i++)
	{
		leftRight = false;
		tempOne = 0;

		for (int j = 0; j < W; j++)
		{
			if (map[j][i] == 1)
			{
				if (!leftRight)
				{
					// �¿��� ��� �˻��ϴ� ó�� ����� ã���� ��ŷ
					leftRight = true;
					tempOne = 0;
				}
				else
				{
					// ��ŷ�� �Ǿ��ִ� ���¿��� ����� ã���� 
					// ������� ī��Ʈ�ϴ� tempOne�� ������� �����ش�.
					// �׸��� 0���� �ʱ�ȭ
					rainwaterCnt += tempOne;
					tempOne = 0;
				}

			}
			else if (map[j][i] == 0)
			{
				// �ش� ��ġ�� ������̰� ù ��� ��ŷ�� �Ǿ��ִٸ� 
				// ������� ī��Ʈ�ϴ� tempOne�� �ϳ� �÷��ݴϴ�.
				if (leftRight)
				{
					tempOne++;
				}

			}
		}
	}
}

int main()
{
	Initialization();
	ReceiveInput();
	CountRainwater();
	if (debugbool) { VisualDebug(); }
	// ����� ����մϴ�.
	cout << rainwaterCnt;
	return 0;
}