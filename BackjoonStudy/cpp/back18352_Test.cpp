#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

constexpr int INF = INT32_MAX;
constexpr int MAXN = 300001;

// ������ ���� N, ������ ���� M, �Ÿ� ���� K, ��� ������ ��ȣ X
int N, M, K, X;

list<int> myList;

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


   // ������ ���� N, ������ ���� M, ������ ���� K, ��� ������ ��ȣ X
   cin >> N >> M >> K >> X;

   // ��� ������ ������ �Է¹ޱ�
   for (int i = 0; i < M; i++) {
       int A, B;
       cin >> A >> B;
       // A -> B :  C
       graph[A].push_back({ B, 1 });
   }

   // �ӽ� ��带 ��� �������� �ʱ�ȭ
   fill(dist, dist + MAXN, INF);

   // �켱���� ť�� ����.
   myPQ.push({ 0, X }); // < first : �Ÿ� , second : ��� �ε��� >
   dist[X] = 0; // ���� ��� �������� �ִ� ��δ� 0���� ����

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
           if (disSum < dist[graph[now][i].first]) {
               // �ӽ� ��� ������Ʈ
               dist[graph[now][i].first] = disSum;
               // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
               myPQ.push(make_pair(-disSum, graph[now][i].first));
           }
       }
   }

   // ����ϴ� �κ�
   int cnt = 0;
   for (int i = 1; i <= N; i++) {
       if (dist[i] == K) {
           myList.push_back(i);
           cnt++;
       }
   }

   if (cnt == 0) cout << -1;
   else 
   {
       myList.sort();
       for (auto it = myList.begin(); it != myList.end(); it++) 
           cout << *it << "\n";
   }

   return 0;
}
