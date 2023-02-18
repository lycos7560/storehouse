
#include<iostream>
#include<stdio.h>
#include <vector>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;
#define MAX 26

int N, cnt = 0; // ���μ���

int map[MAX][MAX];
bool isVisited[MAX][MAX];
vector<int> intvec;

int D[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//                ��       ��      ��       ��


void DFS(int x, int y)
{
	cnt++;
	cout << x << "/" << y << "\n";
	isVisited[x][y] = true;  // �湮�� �ǹ̷� ��ŷ


	for (int i = 0; i < 4; i++)
	{
	//	���� �¿�� �˻�
		int nx = x + D[i][0];
		int ny = y + D[i][1];

		//������ ����� ��쿡 �ѱ�
		if (nx < 0 || nx > N || ny < 0 || ny > N)
		{
			continue;
		}

		if (isVisited[nx][ny] == false && map[nx][ny] == 1)
		{
			DFS(nx, ny);
		}
	}

	
}

//�ʱ�ȭ
void Init()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
			isVisited[i][j] = false;
		}
	}

}

int main()
{
	Init();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && isVisited[i][j] == false)
			{
				cnt = 0;
				DFS(i, j);
				intvec.push_back(cnt);
			}
		}
	}

	cout << intvec.size() << "\n";

	sort(intvec.begin(), intvec.end());

	for (int i = 0; i < intvec.size(); i++)
	{
		cout << intvec[i] << "\n";
	}
	

	
	cout << "\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
	
	

}