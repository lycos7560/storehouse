

#include<iostream>
#include<stack>
#define MAX_N 10


using namespace std;

//��ǥ�� ǥ��
struct Point {

	int row, col;

};

//�����¿�� �����̱� ���� ��Ÿ�� ����
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
              // ��       ��      ��        ��

//���� ũ�� N 
int N, Board[MAX_N][MAX_N];

void dfs(int r, int c, int color)
{
	bool visited[MAX_N][MAX_N] = { false }; // �ʱ�ȭ

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

		visited[curr.row][curr.col] = true; // �湮 ��ŷ
		Board[curr.row][curr.col] = color;

		for (int i = 0; i < 4; ++i)
		{
			int nr = curr.row + D[i][0], nc = curr.col + D[i][1];


			//������ ����� ��ŵ
			if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) 
			{
				continue;
			}

			//�湮�ߴ� ���̸� ��ŵ
			if (visited[nr][nc])
			{
				continue;
			}

			//���� �������� ��ŵ
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
	cin >> N; // ���� ũ�⸦ ����  N X N

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Board[i][j]; // ������ ���� �Է�����
		}

	}

	int sr, sc, color;

	cin >> sr >> sc >> color;

	dfs(sr, sc, color); // �Լ� ȣ��
	
	cout << "\n";

	//����� ���
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << Board[i][j] << ' '; // ������ ���� �Է�����
		}

		cout << endl;
	}

	return 0;
}

