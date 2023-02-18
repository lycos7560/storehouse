
#include <iostream>
#include <queue>

using namespace std;

// �켱 ť�� ���� ���ǰ� ������ �ð��� ������������ ����
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myQueue;

int result = 0;
int startLecture = 0;
int endLecture = 0;
int N = 0;

// ���� �ʱ�ȭ
void Initializtion()
{
	cin >> N;
	while (N > 0)
	{
		cin >> startLecture >> endLecture;
		myQueue.push(make_pair(endLecture, startLecture));
		N--;
	}
}

int main()
{
	Initializtion();

	// ���� �������� ���ǰ� ������ �ð����� ����
	int curEndLecture = 0;

	// ������ �ð��� ���� ���� ���Ǹ� ������
	curEndLecture = myQueue.top().first;
	myQueue.pop();
	result++;

	// �־��� ���Ǹ� ��� Ȯ���Ҷ����� �ݺ�
	while (!myQueue.empty())
	{
		endLecture = myQueue.top().first;
		startLecture = myQueue.top().second;
		myQueue.pop();

		// ������ �ð��� ���� ���ǵ��� ���� �ð��� Ȯ�� 
		// ������ ���۽ð��� ������ �ð��� ���ų� ������
		// ���� �������� ������ �ε����� �ٲپ���
		// (���Ǹ� �����Ѵٴ� �ǹ�)
		if (startLecture >= curEndLecture)
		{
			curEndLecture = endLecture;
			result++;
		}
	}

	cout << result;
	return 0;
}
