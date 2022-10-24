/*
#include<iostream>
#include<cstring>

using namespace std;

#define MAX_N 10
int N, E;  // N -����� ����  E - ������ ����
int Graph[MAX_N][MAX_N]; // ���� �迭�� ǥ��
bool Visited[MAX_N]; // �湮 ���θ� ��ŷ

void dfs(int node)
{
	Visited[node] = true;  // �湮�� �ǹ̷� ��ŷ
	cout << node << ' ';   // �湮�ߴٴ� �ǹ̷� ���
	for (int next = 0; next < N; ++next)
	{
		if (!Visited[next] && Graph[node][next]) // �湮������ �ִ°�?  && ������ �ִ°�?
		{
			dfs(next);
		}
	}


}


int main()
{
	cin >> N >> E;
	memset(Visited, 0, sizeof(Visited)); // ó���� �� 0���� �ʱ�ȭ
	memset(Graph, 0, sizeof(Graph));     // ������ ���� �ʱ�ȭ 

	for (int i = 0; i < E; ++i)
	{
		int u, v;
		cin >> u >> v;
		Graph[u][v] = Graph[v][u] = 1;
		// u -> v �� �� �ִ�. 1�� ����
		// v -> u �� �� �ִ�.
	}

	dfs(0);
	return 0;

}

*/

// https://www.youtube.com/watch?v=M48Po-wTOpU