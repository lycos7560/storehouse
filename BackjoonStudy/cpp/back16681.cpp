#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAXN = 100001;
constexpr long long int INF = INT64_MAX;
constexpr long long int uINF = INT64_MIN;

///*
//�� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� ����
//a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
//graph[a].push_back((make_pair(B, C));
//*/
vector<pair<int, int>> upGraph[MAXN];
vector<pair<int, int>> downGraph[MAXN];

// Dijkstra �˰��� ����� �켱���� ť
priority_queue<pair<long long int, int>> myPQ;

// N ������ ����, M ������ �մ� ����� ����
// D ��ȯ���� �Ÿ� ��� ü�� �Ҹ�, E ���� ��� ���밨 ȹ�淮
int N, M, D, E;

// �� ������ ���̸� �����ϴ� �迭
int hArr[MAXN];

// ����� �ϴµ� �ʿ��� �迭 (�� -> ��)
long long int upArr[MAXN];

long long int temp = 0;
// ����� ����
long long int result = uINF;

// �ϻ��� �ϴµ� �ʿ��� �迭 (�� -> �����)
long long int downArr[MAXN];

// V1,2 ����, d : ���� ������ �Ÿ�
int V1, V2, d;

void Dijkstra(int start, long long int arr[], vector<pair<int, int>> graph[])
{
   // �ӽù迭 �ʱ�ȭ
   for (int i = 1; i <= N; i++) arr[i] = INF;
   // �켱���� ť�� ����.
   myPQ.push({ 0, start }); // < first : �Ÿ� , second : ��� �ε��� >
   arr[start] = 0;
   while (!myPQ.empty()) {
       // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
       // (�ּ������� ����)
       long long int nCost = -myPQ.top().first;
       int now = myPQ.top().second;
       myPQ.pop();
       // �̹� ��� �ִ� �ͺ��� �Ÿ��� ũ�� �Ѿ��.
       if (arr[now] < nCost) continue;
       // �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {
           // disSum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           long long int disSum = nCost + graph[now][i].second;
           // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           if (disSum < arr[graph[now][i].first]) {
               // �ӽ� ��� ������Ʈ
               arr[graph[now][i].first] = disSum;
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

   // ������ ���ǵ��� �Է� �޴´�.
   cin >> N >> M >> D >> E;

   // �� ������ ���̸� �Է� �޴´�.
   for (int i = 1; i <= N; i++) cin >> hArr[i];

   // ��θ� �Է� �޴´�.
   for (int i = 0; i < M; i++) {

       cin >> V1 >> V2 >> d;

       // ���̰� ���� ��쿡�� �������� �ʴ´�.
       if (hArr[V1] > hArr[V2]) { // V1�� ���̰� �� ���� ���
           upGraph[V2].push_back(make_pair(V1, d));
           downGraph[V2].push_back(make_pair(V1, d));
       }
       else if (hArr[V1] < hArr[V2]) { // V1�� ���̰� �� ���� ���
           upGraph[V1].push_back(make_pair(V2, d));
           downGraph[V1].push_back(make_pair(V2, d));
       }

   }
   Dijkstra(1, upArr, upGraph);

   Dijkstra(N, downArr, downGraph);

   for (int i = 1; i <= N; i++) {
       if (upArr[i] == INF || downArr[i] == INF) continue;
       temp = upArr[i] + downArr[i];
       result = max(result, hArr[i] * E - temp * D);
   }

   if (result == uINF) cout << "Impossible";
   else cout << result;


   return 0;
}