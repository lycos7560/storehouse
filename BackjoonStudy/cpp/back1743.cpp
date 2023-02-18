
#include<iostream>
#include<stack>

using namespace std;

#define MAX 101

int N, M, K, cnt ,result; // ����,���� // �������� ���� // �ִ� ����

// ��ǥ�� ǥ��
struct Point {

	int x, y;

};

int D[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
              //  ��       ��      ��       ��

char map[MAX][MAX];
bool isVisited[MAX][MAX];

// �ʱ�ȭ
void Init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = '.';
			isVisited[i][j] = false;
		}
	}

	//���Ĺ��� ���� ��ŭ �Է��� ����
	for (; K >= 1; K--)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] ='#';
		// ���Ĺ��� �ִ� �� #
	}
}


void DFS(int x, int y)
{
	stack<Point> mystack;
	mystack.push({ x, y });

	while(!mystack.empty())
	{

		Point curr = mystack.top();
		mystack.pop();


		// �湮 �ߴٸ� �ѱ�
		if (isVisited[curr.x][curr.y])
		{
			continue;
		}

		// �湮 ��ŷ
		isVisited[curr.x][curr.y] = true;
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			// ���� �¿�� �˻�
			int nx = curr.x + D[i][0];
			int ny = curr.y + D[i][1];

			// ������ ����� ��쿡 �ѱ�
			if (nx <= 0 || nx > N || ny <= 0 || ny > M)
			{
				continue;
			}

			if (isVisited[nx][ny])
			{
				continue;
			}

			if (map[nx][ny] == '.')
			{
				continue;
			}

			mystack.push({ nx, ny });
			
		}
	}
}


int main()
{
	cin >> N >> M >> K;

	// �ʱ�ȭ
	Init();

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			// ���Ĺ��� �ְ� �湮�� ���� ���� ��� ����
			if (map[i][j] == '#' && isVisited[i][j] == false)
			{
				cnt = 0;
				DFS(i, j);
				if (result < cnt)
				{
					result = cnt;
				}
			}
		}
	}

	std::cout << result;

	return 0;
	
}
