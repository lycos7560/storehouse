#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// N(1 �� N �� 1,000)���� ��ǻ��
constexpr int MAXN = 1001;
constexpr int INF = INT32_MAX;

///*
//�� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� ����
//a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
//graph[a].push_back((make_pair(B, C));
//*/
vector<pair<int, int>> graph[MAXN];

// Dijkstra �˰��� ����� �켱���� ť
priority_queue<pair<int, int>> myPQ;

// ������ ����� ����ϱ� ���� map 
map<int, int> myMap;

// dist[i][j]  
// => i ���� j ������ �ִܰŸ� (�ӽ� ���)
int timeArr[MAXN];

// dist[i][j]  
// => i ���� j ������ �ִܰŸ� (�ӽ� ���)
int cntArr[MAXN];

// N : ������ ����, M : ������ ����
// U: ���� ���, V : �̿� ���, t : ��� �ð�
int N, M, U, V, t;


void Dijkstra(int start)
{
   // �ӽù迭 �ʱ�ȭ
   for (int i = 1; i <= N; i++) timeArr[i] = INF;
   // �켱���� ť�� ����.
   myPQ.push({ 0, start }); // < first : �Ÿ� , second : ��� �ε��� >
   timeArr[start] = 0;

   while (!myPQ.empty()) {
       // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
       // (�ּ������� ����)
       int nCost = -myPQ.top().first;
       int now = myPQ.top().second;
       myPQ.pop();

       // �̹� ��� �ִ� �ͺ��� �Ÿ��� ũ�� �Ѿ��.
       if (timeArr[now] < nCost) continue;

       // �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {
           // 0�̶�� ���� ���ٴ� �ǹ� continue
           if (graph[now][i].second == 0) continue;
           // disSum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           int disSum = nCost + graph[now][i].second;
           // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           if (disSum < timeArr[graph[now][i].first]) {
               // �ӽ� ��� ������Ʈ
               timeArr[graph[now][i].first] = disSum;
               // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
               myPQ.push(make_pair(-disSum, graph[now][i].first));

               // ���� map�� key ���� ��ģ�ٸ� �ش� ���� �����.
               if (myMap.count(graph[now][i].first)) myMap.erase(graph[now][i].first);
               // �������� Key ������ map�� ����
               myMap.insert(make_pair(graph[now][i].first, now));
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

   cin >> N >> M;

   for (int i = 0; i < M; i++) {
       cin >> U >> V >> t;
       // ����� ��� ����
       graph[U].push_back(make_pair(V, t));
       graph[V].push_back(make_pair(U, t)); 
   }

   Dijkstra(1);

   // map�� ����� ����մϴ�.
   cout << myMap.size() << "\n";

   // ������ ȸ���� ���
   for (auto it = myMap.begin(); it != myMap.end(); it++) 
       cout << it->first << " " << it->second << "\n";

	return 0;
}
