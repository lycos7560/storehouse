#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAXN = 8001;
constexpr int INF = INT32_MAX;

// Dijkstra �˰��� ����� �켱���� ť
priority_queue<pair<int, int>> myPQ;

///*
//�� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� ����
//a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
//graph[a].push_back((make_pair(B, C));
//*/
vector<pair<int, int>> graph[MAXN];

// �ӽó�� dist[i][j] 
// i = 0  ����
// 1, 2 ����
int disArr[3][MAXN];

// N : ������ ����, E : ������ ����
// U: ���� ���, V : �̿� ���, dist : �Ÿ�
// V1, V2 �ʼ� ����
int N, E, U, V, dist, V1, V2;

int result = 0;

void Dijkstra(int start, int number)
{
   // �ӽù迭 �ʱ�ȭ
   for (int i = 1; i <= N; i++) disArr[number][i] = INF;
   // �켱���� ť�� ����.
   myPQ.push({ 0, start }); // < first : �Ÿ� , second : ��� �ε��� >

   disArr[number][start] = 0;

   while (!myPQ.empty()) {
       // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
       // (�ּ������� ����)
       int nCost = -myPQ.top().first;
       int now = myPQ.top().second;
       myPQ.pop();
       // �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {
           // 0�̶�� ���� ���ٴ� �ǹ� continue
           if (graph[now][i].second == 0) continue;
           // disSum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           int disSum = nCost + graph[now][i].second;
           // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           if (disSum < disArr[number][graph[now][i].first]) {
               // �ӽ� ��� ������Ʈ
               disArr[number][graph[now][i].first] = disSum;
               // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
               myPQ.push(make_pair(-disSum, graph[now][i].first));
           }
       }
   }
}

int main()
{
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(NULL);
   cout.tie(NULL);

   // N ������ ����, E ������ ������ �Է¹޴´�.
   cin >> N >> E;

   for (int i = 0; i < E; i++) {
       cin >> U >> V >> dist;

       // �����
       graph[U].push_back(make_pair(V, dist));
       graph[V].push_back(make_pair(U, dist));
   }

   // V1, V2 �ʼ� ������ �Է¹޴´�.
   cin >> V1 >> V2;

   Dijkstra(1, 0);
   Dijkstra(V1, 1);
   Dijkstra(V2, 2);

   // 1 -> V1 -> V2 -> N �� 1 -> V2 -> V1 -> N �� ��
   result = min(disArr[0][V2] + disArr[2][V1] + disArr[1][N], disArr[0][V1] + disArr[1][V2] + disArr[2][N]);

   // 1 -> N ���� ���� ��� �Ǵ� 
   if (disArr[0][N] == INF || disArr[1][V2] == INF) cout << -1;
   else cout << result;

   return 0;
}