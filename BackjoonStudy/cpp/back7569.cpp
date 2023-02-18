#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

constexpr int MAX = 100;

// N ����, M ����, H ����
int N, M, H, dx, dy, dz, maxCnt = 0;

// N, M�� ���� 
int map[MAX][MAX][MAX];

// BFS �湮ó��
bool mapCheck[MAX][MAX][MAX];

// Ž���ϴ� ���� ����
int dxdydz[6][3] = { 
        {0, 0, 1},
        {0, 0, -1},
        {1, 0, 0},
        {-1, 0, 0},
        {0, 1, 0},
        {0, -1, 0}
};

queue<tuple<int, int, int>> myQueue;

tuple<int, int, int> tempTuple;

bool falseCheck = true;

int main()
{
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> M >> N >> H;


   for (int k = 0; k < H; k++) {
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < M; j++) {              
                   cin >> map[i][j][k];    
           }
       }
   }

   for (int  k = 0; k < H; k++) {
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < M; j++) {
               if (map[i][j][k] == 1) { // ���� �丶�並 ť�� �ְ� �湮ó��
                   mapCheck[i][j][k] = true;
                   map[i][j][k] = 0; // map[i][j][k] = ���� ��¥
                   myQueue.push(make_tuple(i, j, k));
               }
           }
       }
   }


   while (!myQueue.empty()) {

       tempTuple = myQueue.front();
       myQueue.pop();
       // ��/��/��/�츦 Ž���ϱ� ���� �ݺ���
       for (int i = 0; i < 6; i++) {
           dx = get<0>(tempTuple) + dxdydz[i][0];
           dy = get<1>(tempTuple) + dxdydz[i][1];
           dz = get<2>(tempTuple) + dxdydz[i][2];


           // ������ ������ ����� ��� => �Ѿ��.
           if (dx < 0 || dy < 0 || dz < 0 || dx >= N || dy >= M || dz >= H) continue;
           // '-1' �� ���, �̹� �湮�� �� �� ��� => �Ѿ��.
           if (mapCheck[dx][dy][dz] == true || map[dx][dy][dz] == -1) continue;

           map[dx][dy][dz] = map[get<0>(tempTuple)][get<1>(tempTuple)][get<2>(tempTuple)] + 1; // ī��Ʈ�� �÷��ش�.
           mapCheck[dx][dy][dz] = true; // �湮ó��
           myQueue.push(make_tuple(dx, dy, dz));
       }
   }

   for (int k = 0; k < H && falseCheck; k++) {
       for (int i = 0; i < N && falseCheck; i++) {
           for (int j = 0; j < M && falseCheck; j++) {
                   maxCnt = max(maxCnt, map[i][j][k]); // ��¥ ���
                   // ���� ���� �丶�䰡 �湮ó���� �ȵǾ��ִٸ� �����ִٴ� �� 
                   if (map[i][j][k] == 0 && mapCheck[i][j][k] == false)  falseCheck = false;
           }
       }
   }

   // ���� ���� �丶�䰡 �ִٸ� -1 ���
   // ���ٸ� ��¥ ���
   if (falseCheck) cout << maxCnt;
   else cout << -1;

   return 0;
}