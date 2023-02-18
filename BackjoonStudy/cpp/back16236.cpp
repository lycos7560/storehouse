#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

// �ִ� ���� 
constexpr int MAX = 20;

// ��/��/��/��
int dxdy[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

pair<int, int> Shark; // ��� ũ��, ����ġ?

tuple<int, int, int> posShark; // ����� x, y��ġ / �ð�

tuple<int, int, int> tempT;

int N, dx, dy;

int map[MAX][MAX]; // ��

bool eatMap[MAX][MAX]; // ���� �� �ִ� ����� üũ

bool mapCheck[MAX][MAX]; // BFS �湮 üũ�� ���

// BFS Ž��, ��ȯ���� ����� ��ġ�� �ð�
tuple<int, int, int> SharkBFS()
{
   queue<tuple<int, int, int>> myQ;

   // �湮ó�� �ʱ�ȭ
   fill(&mapCheck[0][0], &mapCheck[N - 1][N], false);
   fill(&eatMap[0][0], &eatMap[N - 1][N], false);

   myQ.push(posShark);
   mapCheck[get<0>(posShark)][get<1>(posShark)] = true;

   int dis = 99999;
   while (!myQ.empty()) {
       tempT = myQ.front();
       myQ.pop();

       // ��/��/��/�츦 Ž���ϱ� ���� �ݺ���
       for (int i = 0; i < 4; i++) {
           dx = get<0>(tempT) + dxdy[i][0];
           dy = get<1>(tempT) + dxdy[i][1];

           // ������ ������ ����� ��� => �Ѿ��.
           if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
           // �̹� �湮�� �� �� ���� �ش� ĭ�� ����Ⱑ ���� Ŭ ��� => �Ѿ��.
           if (mapCheck[dx][dy] == true || map[dx][dy] > Shark.first) continue;

           // �� �� ũ��, �� ������ �ƴ϶�� 
           if (map[dx][dy] < Shark.first && map[dx][dy] != 0 ) {

               if (get<2>(tempT) + 1 <= dis) {
                   eatMap[dx][dy] = true;
                   dis = get<2>(tempT) + 1;
               }
           }

           mapCheck[dx][dy] = true; // �湮ó��
           myQ.push(make_tuple(dx, dy, get<2>(tempT) + 1)); // Ž�� Q�� �ֱ�
       }
   }

   // ���� �� �ִ� ������ �߿��� 
   // ���� ��, ������ �ִ� ����⸦ �����Ѵ�.
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           if (eatMap[i][j] == true) {
               Shark.second++;
               map[i][j] = 0;
               if (Shark.first == Shark.second) {
                   Shark.first++;
                   Shark.second = 0;
               }

               return make_tuple(i, j, dis);
           }
       }
   }
   
   // ���ٸ� ���� ����� ��ġ�� ��ȯ�Ѵ�.
   return posShark;
}


int main()
{
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(NULL);
   cout.tie(NULL);

   Shark = make_pair(2, 0);

   cin >> N;
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           cin >> map[i][j];
           if (map[i][j] == 9) { // ����� ��ġ�� ����
               posShark = make_tuple(i, j, 0);
               map[i][j] = 0;
           }
       }
   }

   bool check = true;
   while (check) {
       check = false;
       for (int i = 0; i < N && !check; i++) {
           for (int j = 0; j < N && !check; i++) {
               if (map[i][j] >= 1) check = true;
           }
       }

       tempT = SharkBFS();
       
       // BFS Ž�� �Ŀ��� ����� �������� ���ٸ� ���� �� �ִ� ����Ⱑ ����.
       if (get<2>(tempT) == get<2>(posShark)) break;
       else posShark = tempT;
 
   }

   cout << get<2>(posShark);

	return 0;
}
