/*
#include<iostream>
#include<queue>

using namespace std;
#define MAX 1001

int N, M, V; // 정점의 개수, 간선의 개수, 시작정점
int map[MAX][MAX]; // 인접 행렬의 그래프
bool visited[MAX]; // 정점의 방문 여부
queue<int> q;

void Reset()
{
	for (int i = 0; i <= N; i++)
	{
		visited[i] = 0; // 방문 초기화
	}
}

void DFS(int v)
{
	// 해당 정점 방문으로 변경
	visited[v] = true;
	cout << v << " ";

	for (int i = 1; i <= N; i++)
	{
		// 현재 정점과 연결되어있고 방문되지 않았으면 실행
		if (map[v][i] == 1 && visited[i] == 0)
		{
			DFS(i); // 재귀
		}
	}

}

void BFS(int v)
{
	q.push(v); // 해당점점 queue에 푸시
	visited[v] = true; // 해당 정점 방문으로 변경
	cout << v << " ";

	while(!q.empty()) // queue가 비어있지 않으면 실행
	{
		v = q.front(); // queue 제일 앞에 있는 원소를 반환
		q.pop(); // queue 제일 앞에 있는 원소를 반환

		for (int j = 1; j <= N; j++)
		{
			// 현재의 정점과 연결되어 있고 방문되지 않았으면 실행
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
