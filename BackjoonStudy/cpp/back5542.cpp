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
   // 임시배열 초기화
   for (int i = 1; i <= N; i++) tempArr[i] = INF;
   // 우선순위 큐에 삽입.
   myPQ.push({ 0, start }); // < first : 거리 , second : 노드 인덱스 >
   tempArr[start] = 0;
   while (!myPQ.empty()) {
       // -를 붙이는 이유는 우선순위 큐를 이용하여 정렬하기 위함이다.
       // (최소힙으로 구현)
       long long int nCost = -myPQ.top().first;
       int now = myPQ.top().second;
       myPQ.pop();
       // 이미 담겨 있는 것보다 거리가 크면 넘어간다.
       if (tempArr[now] < nCost) continue;
       // 해당 노드에서 연결된 모든 경로를 확인
       for (int i = 0; i < graph[now].size(); i++) {
           // disSum = 임시 노드 + 현재 노드에서 i로가는 비용
           long long int disSum = nCost + graph[now][i].second;
           // 비용이 더 작다면 최단경로 테이블 값을 갱신.
           if (disSum < tempArr[graph[now][i].first]) {
               // 임시 노드 업데이트
               tempArr[graph[now][i].first] = disSum;
               // 우선순위 큐에 (거리, 노드 인덱스) 푸시
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
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> Q;

	for (int i = 0; i < M; i++) {
		cin >> V1 >> V2 >> d;
		// 양방향 그래프
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