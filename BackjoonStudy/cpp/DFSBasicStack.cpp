
#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

#define MAX_N 10
int N, E;  // N -노드의 개수  E - 간선의 개수
int Graph[MAX_N][MAX_N]; // 인접 배열로 표현


void dfs(int node)
{
	bool visited[MAX_N] = {false}; // 미방문으로 마킹

	stack<int> mystack;

	mystack.push(node);

	while (!mystack.empty())
	{
		int curr = mystack.top(); // 가장 위에있는 값을 리턴만함
		mystack.pop(); // 가장 위의 값을 꺼내면서 제거

		if (visited[curr])  // 방문했다면
		{
			continue; // 스킵
		}

		visited[curr] = true; // 방문했다고 마킹

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
	memset(Graph, 0, sizeof(Graph));     // 간선의 정보 초기화 

	for (int i = 0; i < E; ++i)
	{
		int u, v;
		cin >> u >> v;
		Graph[u][v] = Graph[v][u] = 1;
		u -> v 갈 수 있다. 1로 변경
		v -> u 갈 수 있다.
	}

	dfs(0);
	return 0;

}
