#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

constexpr int MAXN = 101;
constexpr int INF = INT32_MAX;

// Ž���ϴ� ���� ���� =>  ��, �� ,�� ,��
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int M, N, nowX, nowY, dcost;

string str;

int map[MAXN][MAXN], dis[MAXN][MAXN];

tuple<int, int, int> nowTuple;

// ����ġ, x,y ��ǥ
priority_queue<tuple<int, int, int>> myPQ;


int main()
{
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> M >> N;
   for (int i = 1; i <= N; i++) {
       cin >> str;
       for (int j = 0; j < M; j++) {
           map[i][j + 1] = str[j] - '0';
       }
   }

   // 2���� �迭 �ʱ�ȭ
   // ��ü �ʱ�ȭ : ó������ [0][0]�� ���ְ�, 
   // �� ���� ĭ���� [�ִ� ��(��) - 1][�ִ� ��], ���� ĭ���� �ʱ� ������ ��
   // �������� �ӽ� ��带 ���Ѵ� ����
   fill(&dis[0][0], &dis[MAXN - 1][MAXN], INF);

   // �켱���� ť�� �̿��ϱ� ���Ͽ� ������ �ִ� ���� �������
   myPQ.push(make_tuple(-map[1][1], 1, 1));
   dis[1][1] = 0; // �ʱ�ȭ

   while (!myPQ.empty()) {

       // 0�� �ε��� ����ġ, 1�� �ε��� X��ǥ, 2�� �ε��� Y��ǥ
       nowTuple = myPQ.top();
       myPQ.pop();

       if (get<1>(nowTuple) == N && get<2>(nowTuple) == M) break;

       // ��/��/��/�츦 Ž���ϱ� ���� �ݺ���
       for (int i = 0; i < 4; i++) {
           nowX = get<1>(nowTuple) + dxdy[i][0];
           nowY = get<2>(nowTuple) + dxdy[i][1];
           dcost = get<0>(nowTuple) * -1;

           // ������ ������ ����� ��� => �Ѿ��.
           if (nowX <= 0 || nowY <= 0 || nowX > M || nowY > N) continue;
           // ���� ��ġ�� �ּ� ���Ϸ��� + ���� ĭ�� ���Ϸ����� ũ�� >= Ž�� ��ġ�� �ּ� ���Ϸ���
           if (dcost + map[nowY][nowX] >= dis[nowY][nowX]) continue;
           else {
               // �ӽ� ��� ������Ʈ
               dis[nowY][nowX] = dcost + map[nowY][nowX];
               myPQ.push(make_tuple(-dis[nowY][nowX], nowX, nowY));
           }
       }
   }

   cout << dis[N][M];
   
   return 0;
}