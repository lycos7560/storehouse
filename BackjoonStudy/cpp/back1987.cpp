
#include <iostream>
#include <queue>
#include <string>
#include <set>

using namespace std;

#define MAX 21

int row, column, result;
char map[MAX][MAX];
//bool mapcheck[MAX][MAX] = {false};
set<string> mySet;

struct Pos {
	// 나의 위치, 이동 횟수
	int posX, posY, trace;
	string strTrace;
} sPos;

// 나의 위치를 표현
queue<Pos> myQueue;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			map[i][j] = 'x';
		}
	}

	cin >> row >> column;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= column; j++)
		{
			char temp = ' ';
			cin >> temp;
			map[i][j] = temp;
		}
	}

	result = 0;
	sPos.posX = 1;
	sPos.posY = 1;
	sPos.trace = 0;
	sPos.strTrace = "";
	myQueue.push(sPos);

	while (!myQueue.empty())
	{
		Pos temp = myQueue.front();
		myQueue.pop();
		temp.strTrace.push_back(map[temp.posX][temp.posY]);
		temp.trace += 1;
		
		if (result < temp.trace) result = temp.trace;
		if (mySet.count(temp.strTrace) == 0) mySet.insert(temp.strTrace);

		for (int i = 0; i < 4; i++)
		{
			int nx = temp.posX + dx[i];
			int ny = temp.posY + dy[i];

			if (nx <= 0 || nx > MAX || ny <= 0 || ny > MAX) continue;
			if (map[nx][ny] == 'x') continue;
			if (temp.strTrace.find(map[nx][ny]) != string::npos) continue;

			Pos temp2 = temp;
			temp2.posX = nx;
			temp2.posY = ny;

			string check = temp2.strTrace;
			check.push_back(map[nx][ny]);

			if (mySet.count(check) == 0)
			{
				cout << check << "\n";
				mySet.insert(check);
				myQueue.push(temp2);
			}
		}
	}

	cout << result;
	return 0;
}