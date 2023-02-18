#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

constexpr long long int INF = INT64_MAX;

long long int disArr[10001][21];

priority_queue<tuple<long long int, int, int>> myPQ;

vector<pair<int, int>> graph[50000];

int N, M, K, U, V, dist, cnt;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {

		cin >> U >> V >> dist;
       // ����� ����
		graph[U].push_back(make_pair(V, dist));

       graph[V].push_back(make_pair(U, dist));

	}

   // ���ͽ�Ʈ�� �迭 �ʱ�ȭ
	for (int i = 1; i <= N; i++)
       for (int j = 0; j <= 20; j++)
           disArr[i][j] = INF;


	// �켱���� ť�� ����.
	myPQ.push({ 0, 1, 0 }); // < first : �Ÿ� , second : ��� �ε��� >

	disArr[1][0] = 0;

   while (!myPQ.empty()) {
       // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
       // (�ּ������� ����)
       long long int nCost = -get<0>(myPQ.top());

       int now = get<1>(myPQ.top());

       int cnt = get<2>(myPQ.top()); // ���尳��

       myPQ.pop();
       // �̹� ��� �ִ� �ͺ��� �Ÿ��� ũ�� �Ѿ��.
       if (disArr[now][cnt] < nCost) continue;
       // �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {

           // disSum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           long long int disSum = nCost + graph[now][i].second;

           // ����� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           // ���ΰ� ������ ������ ���
           if (disSum < disArr[graph[now][i].first][cnt]) {
               // �ӽ� ��� ������Ʈ
               disArr[graph[now][i].first][cnt] = disSum;
               // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
               myPQ.push({ -disSum, graph[now][i].first, cnt});

           }

           // ����� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           // ���ΰ� ������ ���� ��� �̵����� 0
           // ������ �� �ִ� ������ ������ ������ �ȵȴ�.
           if (nCost < disArr[graph[now][i].first][cnt + 1] && cnt < K) {
               // �ӽ� ��� ������Ʈ
               disArr[graph[now][i].first][cnt + 1] = nCost;

               myPQ.push({ -nCost, graph[now][i].first, cnt + 1 });

           }
       }
   }

   long long int result = INF;

   for (int j = 0; j <= K; j++) result = min(disArr[N][j], result);
   
   cout << result;
 
	return 0;
}

