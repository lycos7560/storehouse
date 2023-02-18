#include <iostream>
#include <list>
#include <set>

using namespace std;

int T;

string tempString;

list<string> testCase;

int directionTurtle[4][2] = {
	{0, 1 },
	{1, 0 },
	{0, -1},
	{-1, 0}
};

// �ʱ�ȭ
void Initializtion()
{
	cin >> T;
	while (T > 0)
	{
		cin >> tempString;
		testCase.push_back(tempString);
		T--;
	}

}

// �ź��̰� ������ ������ �����ϴ� ���� ���� ���簢�� ��� �Լ� 
int SizeCalculation(string testcase)
{
	int curX = 0;
	int curY = 0;
	int conditionTurtle = 0;
	set<int> xSet;
	set<int> ySet;
	xSet.insert(curX);
	ySet.insert(curY);

	// ��ɾ ó���ϴ� �κ�
	for (int i = 0; i < testcase.size(); i++)
	{
		switch (testcase[i])
		{
			case 'F': // ����
				curX += directionTurtle[conditionTurtle][0];
				curY += directionTurtle[conditionTurtle][1];
				break;

			case 'B': // ����
				curX -= directionTurtle[conditionTurtle][0];
				curY -= directionTurtle[conditionTurtle][1];
				break;

			case 'L': // �������� 90�� ȸ��
				conditionTurtle--;
				if (conditionTurtle <= -1) {
					conditionTurtle = 3; }
				break;

			case 'R': // �������� 90�� ȸ��
				conditionTurtle++;
				if (conditionTurtle >= 4) {
					conditionTurtle = 0; }
				break;

			default:
				cout << "�̰� ������ ū�ϳ�";
				break;
		}

		xSet.insert(curX);
		ySet.insert(curY);
	}

	// Set<int>�� �̿��Ͽ� x,y�� ���� ���� ���� �������� ����Ͽ� ���簢�� ���� ���θ� ���Ѵ�.
	int width = *xSet.begin() - *--xSet.end();
	int height = *ySet.begin() - *--ySet.end();

	return abs(width * height);
}


int main()
{
	Initializtion();
	 
	//�׽�Ʈ ���̽� ��ŭ �ݺ�
	for (auto iter = testCase.begin(); iter != testCase.end(); iter++)
	{
		cout << SizeCalculation(*iter) << "\n";
	}

	return 0;
}