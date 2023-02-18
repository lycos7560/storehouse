#include <iostream>
#include <queue>

using namespace std;

#define Max 101 

int kinshipArr[Max][Max];
// �θ� �ڽ� ���踦 ǥ�� �⺻ 0 ;

int checkArr[Max];

int inputPeopleNumber, targetX, targetY;
// �Է¹��� ����� ��, �̼��� ����� x,y  

queue<int> myQ;


// ��ü������ �ʱ�ȭ �����ִ� �Լ�
void Initialization()
{
	// ������ ��
	int degreeOfKinshipNumber;
	
	cin >> inputPeopleNumber >> targetX >> targetY >> degreeOfKinshipNumber;

	// �̼� �迭 �ʱ�ȭ
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			kinshipArr[i][j] = 0;
			kinshipArr[j][i] = 0;

		}

		checkArr[i] = 0;
	}

	// �Է¹��� ������ �� ��ŭ �ݺ� 
	while (degreeOfKinshipNumber > 0)
	{
		int x, y;
		cin >> x >> y;

		// �̼��� ����ϸ�ǹǷ� ���⼺�� �ǹ̾��� 
		kinshipArr[x][y] = 1;
		kinshipArr[y][x] = 1;

		degreeOfKinshipNumber--;
	}
}


// BFS�Լ�
void BFS(int targetX)
{
	myQ.push(targetX);

	// Q�� ������������� �ݺ�
	while (!myQ.empty())
	{
		int a = myQ.front();
		myQ.pop();

		// ����� ��ŭ �ݺ�
		for (int i = 1; i <= inputPeopleNumber; i++)
		{
			// ���谡 ���ų� �湮�� ���� ������ �Ѿ��.
			if (kinshipArr[i][a] == 0 || checkArr[i] != 0) 
			{
				continue;
			} 
			
			myQ.push(i);
			checkArr[i] = checkArr[a] + 1; 
			// targetX�� ��� ������� �̼��� ���
		}
	}
}

int main()
{
	Initialization();
	BFS(targetX);
	
	int result;
	// targetY�� ���� �����ͼ� �̼��� �ִ��� ������ �Ǻ�
	if (checkArr[targetY] == 0)
	{
		result = -1;
	}
	else
	{
		result = checkArr[targetY];
	}

	cout << result;
	return 0;
}