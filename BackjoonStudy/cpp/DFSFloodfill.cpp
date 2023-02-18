

#include<iostream>
#include<stack>
#define MAX_N 10


using namespace std;

//좌표를 표현
struct Point {

	int row, col;

};

//상하좌우로 움직이기 위한 델타값 정의
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
              // 상       하      좌        우

//판의 크기 N 
int N, Board[MAX_N][MAX_N];

void dfs(int r, int c, int color)
{
	bool visited[MAX_N][MAX_N] = { false }; // 초기화

	stack<Point> mystack;
	mystack.push({ r, c });

	while (!mystack.empty())
	{
		Point curr = mystack.top();
		mystack.pop();

		
		if (visited[curr.row][curr.col]) 
		{
			continue;
		}

		visited[curr.row][curr.col] = true; // 방문 마킹
		Board[curr.row][curr.col] = color;

		for (int i = 0; i < 4; ++i)
		{
			int nr = curr.row + D[i][0], nc = curr.col + D[i][1];


			//범위를 벗어나면 스킵
			if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) 
			{
				continue;
			}

			//방문했던 곳이면 스킵
			if (visited[nr][nc])
			{
				continue;
			}

			//벽을 만났을시 스킵
			if (Board[nr][nc] == 1)
			{
				continue;
			}

			mystack.push({ nr,nc });
		}

	}


}




int main()
{
	cin >> N; // 판의 크기를 받음  N X N

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Board[i][j]; // 보드의 값을 입력해줌
		}

	}

	int sr, sc, color;

	cin >> sr >> sc >> color;

	dfs(sr, sc, color); // 함수 호출
	
	cout << "\n";

	//결과를 출력
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << Board[i][j] << ' '; // 보드의 값을 입력해줌
		}

		cout << endl;
	}

	return 0;
}

