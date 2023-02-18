#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAXN = 100001;
constexpr long long int INF = INT64_MAX;
constexpr long long int uINF = INT64_MIN;

///*
//각 노드에 연결되어 있는 노드에 대한 정보를 담는 벡터
//a번 노드에서 b번 노드로 가는 비용이 c라는 의미
//graph[a].push_back((make_pair(B, C));
//*/
vector<pair<int, int>> upGraph[MAXN];
vector<pair<int, int>> downGraph[MAXN];

// Dijkstra 알고리즘에 사용할 우선순위 큐
priority_queue<pair<long long int, int>> myPQ;

// N 지점의 개수, M 지점을 잇는 경로의 개수
// D 주환이의 거리 비례 체력 소모량, E 높이 비례 성취감 획득량
int N, M, D, E;

// 각 지점의 높이를 저장하는 배열
int hArr[MAXN];

// 등산을 하는데 필요한 배열 (집 -> 산)
long long int upArr[MAXN];

long long int temp = 0;
// 결과를 저장
long long int result = uINF;

// 하산을 하는데 필요한 배열 (산 -> 고려대)
long long int downArr[MAXN];

// V1,2 지점, d : 지점 사이의 거리
int V1, V2, d;

void Dijkstra(int start, long long int arr[], vector<pair<int, int>> graph[])
{
   // 임시배열 초기화
   for (int i = 1; i <= N; i++) arr[i] = INF;
   // 우선순위 큐에 삽입.
   myPQ.push({ 0, start }); // < first : 거리 , second : 노드 인덱스 >
   arr[start] = 0;
   while (!myPQ.empty()) {
       // -를 붙이는 이유는 우선순위 큐를 이용하여 정렬하기 위함이다.
       // (최소힙으로 구현)
       long long int nCost = -myPQ.top().first;
       int now = myPQ.top().second;
       myPQ.pop();
       // 이미 담겨 있는 것보다 거리가 크면 넘어간다.
       if (arr[now] < nCost) continue;
       // 해당 노드에서 연결된 모든 경로를 확인
       for (int i = 0; i < graph[now].size(); i++) {
           // disSum = 임시 노드 + 현재 노드에서 i로가는 비용
           long long int disSum = nCost + graph[now][i].second;
           // 비용이 더 작다면 최단경로 테이블 값을 갱신.
           if (disSum < arr[graph[now][i].first]) {
               // 임시 노드 업데이트
               arr[graph[now][i].first] = disSum;
               // 우선순위 큐에 (거리, 노드 인덱스) 푸시
               myPQ.push(make_pair(-disSum, graph[now][i].first));
           }
       }
   }
}


int main()
{
   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(NULL);
   cout.tie(NULL);

   // 문제의 조건들을 입력 받는다.
   cin >> N >> M >> D >> E;

   // 각 지점의 높이를 입력 받는다.
   for (int i = 1; i <= N; i++) cin >> hArr[i];

   // 경로를 입력 받는다.
   for (int i = 0; i < M; i++) {

       cin >> V1 >> V2 >> d;

       // 높이가 같을 경우에는 생각하지 않는다.
       if (hArr[V1] > hArr[V2]) { // V1의 높이가 더 높을 경우
           upGraph[V2].push_back(make_pair(V1, d));
           downGraph[V2].push_back(make_pair(V1, d));
       }
       else if (hArr[V1] < hArr[V2]) { // V1의 높이가 더 낮은 경우
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