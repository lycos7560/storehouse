/*
#include<iostream>
#include<queue>

using namespace std;
#define MAX 1001

int N, M, V; // ������ ����, ������ ����, ��������
int map[MAX][MAX]; // ���� ����� �׷���
bool visited[MAX]; // ������ �湮 ����
queue<int> q;

void Reset()
{
	for (int i = 0; i <= N; i++)
	{
		visited[i] = 0; // �湮 �ʱ�ȭ
	}
}

void DFS(int v)
{
	// �ش� ���� �湮���� ����
	visited[v] = true;
	cout << v << " ";

	for (int i = 1; i <= N; i++)
	{
		// ���� ������ ����Ǿ��ְ� �湮���� �ʾ����� ����
		if (map[v][i] == 1 && visited[i] == 0)
		{
			DFS(i); // ���
		}
	}

}

void BFS(int v)
{
	q.push(v); // �ش����� queue�� Ǫ��
	visited[v] = true; // �ش� ���� �湮���� ����
	cout << v << " ";

	while(!q.empty()) // queue�� ������� ������ ����
	{
		v = q.front(); // queue ���� �տ� �ִ� ���Ҹ� ��ȯ
		q.pop(); // queue ���� �տ� �ִ� ���Ҹ� ��ȯ

		for (int j = 1; j <= N; j++)
		{
			// ������ ������ ����Ǿ� �ְ� �湮���� �ʾ����� ����
			if (map[v][j] == 1 && visited[j] == 0)
			{
				q.push(j);
				visited[j] = true;
				cout << j << " ";
			}
		}
	}
}


int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	Reset();
	DFS(V);

	cout << '\n';

	Reset();
	BFS(V);

	return 0;
}
*/
