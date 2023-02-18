#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAXN = 100001;
constexpr long long int INF = INT64_MAX;
constexpr long long int uINF = INT64_MIN;

int N, M, K, Q;

int V1, V2, d;

priority_queue<pair<long long int, int>> myPQ;

vector<pair<int, int>> graph[MAXN];

vector<int> fCity;

vector<pair<int, int>> people;

long long int resultArr[MAXN];

long long int tempArr[MAXN];

void Dijkstra(int start)
{
   // �ӽù迭 �ʱ�ȭ
   for (int i = 1; i <= N; i++) tempArr[i] = INF;
   // �켱���� ť�� ����.
   myPQ.push({ 0, start }); // < first : �Ÿ� , second : ��� �ε��� >
   tempArr[start] = 0;
   while (!myPQ.empty()) {
       // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
       // (�ּ������� ����)
       long long int nCost = -myPQ.top().first;
       int now = myPQ.top().second;
       myPQ.pop();
       // �̹� ��� �ִ� �ͺ��� �Ÿ��� ũ�� �Ѿ��.
       if (tempArr[now] < nCost) continue;
       // �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {
           // disSum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           long long int disSum = nCost + graph[now][i].second;
           // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           if (disSum < tempArr[graph[now][i].first]) {
               // �ӽ� ��� ������Ʈ
               tempArr[graph[now][i].first] = disSum;
               // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
               myPQ.push(make_pair(-disSum, graph[now][i].first));
           }
       }
   }

   for (int i = 1; i <= N; i++) {
       resultArr[i] = min(tempArr[i], resultArr[i]);
   }


}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> Q;

	for (int i = 0; i < M; i++) {
		cin >> V1 >> V2 >> d;
		// ����� �׷���
		graph[V1].push_back(make_pair(V2, d));
		graph[V2].push_back(make_pair(V1, d));
	}

	for (int i = 0; i < K; i++) {
		cin >> d;
		fCity.push_back(d);
	}

	for (int i = 0; i < Q; i++) {
		cin >> V1 >> V2;
		people.push_back(make_pair(V1, V2));
	}

   for (int i = 1; i <= N; i++) resultArr[i] = INF;

   for (int i = 0; i < K; i++) {
       Dijkstra(fCity[i]);
   }

   for (int i = 1; i <= N; i++) {
       cout << i << " : " << resultArr[i] << "\n";
   }

	return 0;
}