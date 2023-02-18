
#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

#define MAX_N 10
int N, E;  // N -����� ����  E - ������ ����
int Graph[MAX_N][MAX_N]; // ���� �迭�� ǥ��


void dfs(int node)
{
	bool visited[MAX_N] = {false}; // �̹湮���� ��ŷ

	stack<int> mystack;

	mystack.push(node);

	while (!mystack.empty())
	{
		int curr = mystack.top(); // ���� �����ִ� ���� ���ϸ���
		mystack.pop(); // ���� ���� ���� �����鼭 ����

		if (visited[curr])  // �湮�ߴٸ�
		{
			continue; // ��ŵ
		}

		visited[curr] = true; // �湮�ߴٰ� ��ŷ

		cout << curr << ' ';

		for (int next = 0; next < N; ++next)
		{
			if (!visited[next] && Graph[curr][next])
			{
				mystack.push(next);
			}

		}

	}


}

int main()
{
	cin >> N >> E;
	memset(Graph, 0, sizeof(Graph));     // ������ ���� �ʱ�ȭ 

	for (int i = 0; i < E; ++i)
	{
		int u, v;
		cin >> u >> v;
		Graph[u][v] = Graph[v][u] = 1;
		u -> v �� �� �ִ�. 1�� ����
		v -> u �� �� �ִ�.
	}

	dfs(0);
	return 0;

}
