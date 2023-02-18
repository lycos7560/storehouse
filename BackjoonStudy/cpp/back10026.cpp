#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX = 100;

queue<pair<int,int>> myPQ;

int N;

// 0:�Ϲ� 1:�������
int cnt[2];

pair<int, int> temp;

string str[MAX];

char normalMap[MAX][MAX]; // �Ϲ����� ���� ��

char rgMap[MAX][MAX]; // ��������� ���� ��

bool mapCheck[MAX][MAX]; // BFS �湮 ó��

// Ž���ϴ� ���� ���� =>  ��, �� ,�� ,��
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };


void BFS(int x, int y, char map[MAX][MAX])
{
   myPQ.push(make_pair(x, y));
   mapCheck[x][y] = true;

   while (!myPQ.empty()) {

       temp = myPQ.front();
       myPQ.pop();

       int nowX, nowY;
       for (int i = 0; i < 4; i++) {
           nowX = temp.first + dxdy[i][0];
           nowY = temp.second + dxdy[i][1];

           // ������ ������ ����� ��� => �Ѿ��.
           if (nowX < 0 || nowY < 0 || nowX >= N || nowY >= N) continue;
           if (map[temp.first][temp.second] != map[nowX][nowY] || mapCheck[nowX][nowY] == true) continue;
 
           mapCheck[nowX][nowY] = true;
           myPQ.push(make_pair(nowX, nowY));
       }
   }

}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)	cin >> str[i];

	for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           // �Ϲ����� ���� ��
           normalMap[i][j] = str[i][j];

           // ���ϻ����� ���� ��
           if (str[i][j] == 'G') rgMap[i][j] = 'R';
           else rgMap[i][j] = str[i][j];

       }
	}

   // �Ϲ����� ���� �� BFS
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           if (mapCheck[i][j] == false) {
               BFS(i, j, normalMap);
               cnt[0]++;
           }
       }
   }

   // �湮ó�� �ʱ�ȭ
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           mapCheck[i][j] = false;
       }
   }

   // ���ϻ����� ���� �� BFS
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           if (mapCheck[i][j] == false) {
               BFS(i, j, rgMap);
               cnt[1]++;
           }
       }
   }

   // ��� ���
   cout << cnt[0] << " " << cnt[1];

	return 0;
}