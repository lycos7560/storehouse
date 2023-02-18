#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

queue<pair<int, int>> myqueue;
list<pair<int, int>> ::iterator iter;

char map[6][12];
bool check[6][12];
int result = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Initalization()
{
	// �ʱ�ȭ
	for (int j = 0; j <= 11; j++)
	{ // ����
		for (int i = 0; i <= 5; i++)
		{ // ����
			map[i][j] = '.';
			check[i][j] = false;
		}
	}

	for (int y = 0; y <= 11; y++)
	{ // ����
	
		for (int x = 0; x <= 5; x++)
		{ // ����

			cin >> map[x][y];
		}
	}
}

void BFS(int i , int j, char ch)
{
	myqueue.push(make_pair(i, j));
	list<pair<int, int>> mylist;

	while (!myqueue.empty())
	{
		pair<int, int> pair = myqueue.front();
		check[pair.first][pair.second] = true; // �湮 ��ŷ
		mylist.push_back(pair); // ����Ʈ�� ���� ���߿� ī��Ʈ
		myqueue.pop();

		for (int k = 0; k < 4; k++)
		{
			// ���� �¿�� �˻�
			int nx = pair.first + dx[k];
			int ny = pair.second + dy[k];

			// ���� ������ �Ѿ // ����� // ���� ���ڰ� �ƴ� ��� �Ѿ  
			if (nx < 0 || nx > 5 || ny < 0 || ny > 12 || check[nx][ny] == true || map[nx][ny] == '.' || map[nx][ny] != ch)
			{
				continue;
			}

			myqueue.push(make_pair(nx, ny));
		}
	}

	// ���� ����� �ѿ䰡 4�� �̻��̶�� 
	if (mylist.size() >= 4)
	{
		for (iter = mylist.begin(); iter != mylist.end(); iter++)
		{
			map[iter->first][iter->second] = '.';
		}

		result++;
	}
}


int main()
{
	Initalization();

	int tempResult = -1;

	while (result != tempResult)
	{
		tempResult = result;

		for (int j = 0; j <= 11; j++)
		{ // ����
			for (int i = 0; i <= 5; i++)
			{ // ����
				if (check[i][j] != true && map[i][j] != '.')
				{
					BFS(i, j, map[i][j]);
					// �湮 �ʱ�ȭ
				}
			}
		}

		for (int x = 0; x <= 5; x++)
		{
			string tempStr = "";
			for (int y = 0; y <= 11; y++)
			{
				if (map[x][y] != '.')
				{
					tempStr.push_back(map[x][y]);
				}
			}
			string temp2;
			for (int temp = 11 - tempStr.size(); temp >= 0; temp--)
			{
				temp2.push_back('.');
			}

			tempStr = temp2 + tempStr;

			for (int y = 0; y <= 11; y++)
			{
				map[x][y] = tempStr[y];
			}
		}

		for (int j = 0; j <= 11; j++)
		{ // ����
			for (int i = 0; i <= 5; i++)
			{ // ����
				check[i][j] = false;
			}
		}

		if (tempResult != result)
		{
			result = tempResult + 1;
		}

	}

	cout << result;

	return 0;
}