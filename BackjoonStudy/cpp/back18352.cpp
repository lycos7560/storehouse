#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int INF = INT_MAX;
constexpr int MAXN = 300000;

// ������ ���� N, ������ ���� M, �Ÿ� ���� K, ��� ������ ��ȣ X
int N, M, K, X;

pair<int, int> temp;

/*
�� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� ����
a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
graph[a].push_back({b, c});
*/
vector< pair<int, int> > graph[MAXN];

// �׷����� ���� ��忡�� ������ �������� �Ÿ��� �����ϴ� �迭 
// �̰��� �� ��忡 ���� �ӽ� �Ÿ��� �����ϴ� �� ���˴ϴ�.
// �ӽ� ���
int dist[MAXN];

// �켱 ���� ť��
// �ӽ� �Ÿ��� ���� ��带 ȿ�������� �����ϴ� �� ���
// <�Ÿ�, ��� �ε���>
priority_queue<pair<int, int>> myPQ;

int main()
{
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(NULL);
   cout.tie(NULL);


   // ������ ���� N, ������ ���� M, �Ÿ� ���� K, ��� ������ ��ȣ X
   cin >> N >> M >> K >> X;

   // ��� ������ ������ �Է¹ޱ�
   for (int i = 0; i < M; i++) {
       int A, B, C;
       cin >> A >> B >> C;
       // A -> B :  C
       graph[A].push_back({ B, C });
   }

   // �ӽ� ��带 ��� �������� �ʱ�ȭ
   fill(dist, dist + MAXN, INF);

   // �켱���� ť�� ����.
   myPQ.push({ 0, X }); // < first : �Ÿ� , second : ��� �ε��� >
   dist[X] = 0; // ���� ��� �������� �ִ� ��δ� 0���� ����

   while (!myPQ.empty()) {

       temp = myPQ.top();
       myPQ.pop();

       // �ӽ� ����� ������ �������� ����� ũ�ٸ� 
       // �̹� üũ�� ���
       // ���� ��� A�� �ӽó�尡 5 / B -> A : 6 
       // �̹� �ִ� ��θ� üũ��
       if (dist[temp.second] < temp.first) continue;

       // �ش� ��忡�� ����� ��θ� Ȯ��
       for (int i = 0; i < graph[temp.second].size(); i++) {

           // disSum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           int disSum = temp.first + graph[temp.second][i].second;

           // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           if (disSum < dist[graph[temp.second][i].first])
           {
               // �ӽ� ��� ������Ʈ
               dist[graph[temp.second][i].first] = disSum;
               // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
               myPQ.push(make_pair(disSum, graph[temp.second][i].first));
           }
       }

   }

   // ��� ���� ���� ���� �ִ� �Ÿ��� ���
   for (int i = 1; i <= N; i++)
   {
       // ������ �� ���� ���, ����(INFINITY)�̶�� ���
       if (dist[i] == INF) {
           cout << "INFINITY" << '\n';
       }
       // ������ �� �ִ� ��� �Ÿ��� ���
       else {
           cout << dist[i] << '\n';
       }
   }



   return 0;
}
