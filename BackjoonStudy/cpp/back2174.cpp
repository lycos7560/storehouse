#include <iostream>
#include <list>

using namespace std;
constexpr auto MAX = 101;

// 0 ����� 
// 1 ~ 100 �κ� 
int map[MAX][MAX];

// A : ������ ����, B : ������ ����
int A, B, N, M;

// ��ɾ� ����ü
struct Command
{
	int robotNumber; // �κ��� ��ȣ
	char orderDir; // �κ��� ������ ����
	int repetition; // �ݺ� Ƚ��
} CS[100];

// ��ɵ��� ������ ����Ʈ�� ����
list<Command> CommandList;
list<Command>::iterator iterCommandList;

// �κ��� ��ġ�� ������ ����
struct robotPos
{
	int x, y;
	int dir;

} RP[100];

// E N W S
int dirXY[4][2] = { {1, 0}, {0,1}, {-1,0}, {0,-1} };

bool debug = false;

// ����� Ȯ�ο� �Լ�
void DebugMap()
{
	cout << "\n";
	// �� ���
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	// ��� Ȯ��
	for (iterCommandList = CommandList.begin(); iterCommandList != CommandList.end(); iterCommandList++)
	{
		cout << "\n" << "robotNumber : " << iterCommandList->robotNumber << " orderDir : " 
			<< iterCommandList->orderDir << "  repetition : " << iterCommandList->repetition;
	}

}

// ������ ������ ��ȯ���ִ� �Լ�
int ChangeDirCharToInt(char ch)
{
	int temp = 0;
	switch (ch)
	{
		case 'E':
			temp = 0;
			break;
		case 'N':
			temp = 1;
			break;
		case 'W':
			temp = 2;
			break;
		case 'S':
			temp = 3;
			break;
	}

	return temp;
}

// �ʱ�ȭ�� ���� �Լ��Դϴ�.
void Initialization()
{
	// ���� ���� ��������� ������ݴϴ�.
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			map[i][j] = 0;
		}
	}
}

// �Է��� �޴� �Լ� �Դϴ�.
void ReceiveInput()
{

	cin >> A >> B >> N >> M;

	int Number = 1;
	int tempOne, tempTwo;
	char tempChar;

	// �κ��� �ʱ� ��ǥ�� ������ �Է¹޽��ϴ�.
	while (N > 0)
	{
		cin >> tempOne >> tempTwo >> tempChar;
		map[tempOne][tempTwo] = Number;
		RP[Number - 1].x = tempOne;
		RP[Number - 1].y = tempTwo;
		RP[Number - 1].dir = ChangeDirCharToInt(tempChar);
		Number++;
		N--;
	}

	Number = 0;

	// ��ɵ��� ����ü ����Ʈ�� �ֽ��ϴ�.
	while (M > 0)
	{
		cin >> tempOne >> tempChar >> tempTwo;
		CS[Number].robotNumber = tempOne;
		CS[Number].orderDir = tempChar;
		CS[Number].repetition = tempTwo;
		CommandList.push_back(CS[Number]);
		Number++;
		M--;
	}

}

// �ùķ��̼� ����
void SimulationStart()
{
	int cnt, number, tempX, tempY, tempdir;

	// ��� ����Ʈ�� ��ȸ
	for (iterCommandList = CommandList.begin(); iterCommandList != CommandList.end(); iterCommandList++)
	{
		cnt = iterCommandList->repetition;
		number = iterCommandList->robotNumber - 1;
		tempX = RP[number].x;
		tempY = RP[number].y;
		tempdir = RP[number].dir;

		while (cnt > 0)
		{
			switch (iterCommandList->orderDir)
			{
				case 'L': 	// L: �κ��� ���ϰ� �ִ� ������ �������� �������� 90�� ȸ���Ѵ�.
					RP[number].dir ++;
					if (RP[number].dir >= 4)
					{
						RP[number].dir = 0;
					}
					break;

				case 'R':	// R: �κ��� ���ϰ� �ִ� ������ �������� ���������� 90�� ȸ���Ѵ�.
					RP[number].dir--;
					if (RP[number].dir <= -1)
					{
						RP[number].dir = 3;
					}
					break;

				case 'F':	// F : �κ��� ���ϰ� �ִ� ������ �������� ������ �� ĭ �����δ�.
					tempdir = RP[number].dir;
					map[tempX][tempY] = 0;
					tempX += dirXY[tempdir][0];
					tempY += dirXY[tempdir][1];

					// �κ��� ���� �ε��� ��� �Ǵ� ������ ��� ��� ��� ���
					if (tempX <= 0 || tempY <= 0 || tempX > A || tempY > B)
					{
						cout << "Robot "<< number + 1 <<" crashes into the wall";
						return;
					}
					else if (map[tempX][tempY] > 0) // �κ����� �ε��� ���
					{
						cout << "Robot " << number + 1 << " crashes into robot "<< map[tempX][tempY];
						return;
					}
					else // ������ϰ�� �κ��� ��ġ�� �ٲپ��ְ� �ʿ� �κ��� ǥ��
					{
						RP[number].x = tempX;
						RP[number].y = tempY;
						map[tempX][tempY] = number + 1;
					}

					break;

				default:
					cout << "�� ���� ������ �ȵ�";
					break;
			}

			cnt--;
		}
	}

	cout << "OK";

}

int main()
{
	Initialization();
	ReceiveInput();
	SimulationStart();
	if (debug) { DebugMap(); }

	return 0;
}