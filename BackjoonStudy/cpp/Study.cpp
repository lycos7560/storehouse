#include<iostream>
#include<cstring>

using namespace std;

#define MAX_N 10
int N, E;  // N -노드의 개수  E - 간선의 개수
int Graph[MAX_N][MAX_N]; // 인접 배열로 표현
bool Visited[MAX_N]; // 방문 여부를 마킹

void dfs(int node)
{
	Visited[node] = true;  // 방문의 의미로 마킹
	cout << node << ' ';   // 방문했다는 의미로 출력
	for (int next = 0; next < N; ++next)
	{
		if (!Visited[next] && Graph[node][next]) // 방문한적이 있는가?  && 간선이 있는가?
		{
				dfs(next);
		}
	}


}


int main()
{
	cin >> N >> E;
	memset(Visited, 0, sizeof(Visited)); // 처음에 다 0으로 초기화
	memset(Graph, 0, sizeof(Graph));     // 간선의 정보 초기화 

	for (int i = 0; i < E; ++i)
	{
		int u, v;
		cin >> u >> v;
		Graph[u][v] = Graph[v][u] = 1; 
		// u -> v 갈 수 있다. 1로 변경
		// v -> u 갈 수 있다.
	}

	dfs(0); 
	return 0;

}
