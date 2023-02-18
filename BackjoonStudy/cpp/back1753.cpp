#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAXN = 20001;
constexpr int INF = INT32_MAX;

// Dijkstra �˰��� ����� �켱���� ť
priority_queue<pair<int, int>> myPQ;

///*
//�� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� ����
//a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
//graph[a].push_back((make_pair(B, C));
//*/
vector<pair<int, int>> graph[MAXN];

// �ӽó��
int disArr[MAXN];

// v : ������ ����, E : ������ ����, K : ���� ���
// u : ���� ���, v : �̿� ���, dist : �Ÿ�
int V, E, K, u, v, dist;

void Dijkstra(int start)
{
   // �ӽù迭 �ʱ�ȭ
   for (int i = 1; i <= V; i++) disArr[i] = INF;
   // �켱���� ť�� ����.
   myPQ.push({ 0, start }); // < first : �Ÿ� , second : ��� �ε��� >
   disArr[start] = 0;

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
           if (disSum < disArr[graph[now][i].first]) {
               // �ӽ� ��� ������Ʈ
               disArr[graph[now][i].first] = disSum;
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
   cin >> V >> E >> K;

   for (int i = 0; i < E; i++) {
       cin >> u >> v >> dist;
       graph[u].push_back(make_pair(v, dist));
   }

   Dijkstra(K);

   // ���
   for (int i = 1; i <= V; i++) {
       if (disArr[i] == INF) {
           cout << "INF" << "\n";
           continue;
       }

       cout << disArr[i] << "\n";
   }

   return 0;
}