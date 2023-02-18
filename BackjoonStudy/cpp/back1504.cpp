#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAXN = 8001;
constexpr int INF = INT32_MAX;

// Dijkstra 알고리즘에 사용할 우선순위 큐
priority_queue<pair<int, int>> myPQ;

///*
//각 노드에 연결되어 있는 노드에 대한 정보를 담는 벡터
//a번 노드에서 b번 노드로 가는 비용이 c라는 의미
//graph[a].push_back((make_pair(B, C));
//*/
vector<pair<int, int>> graph[MAXN];

// 임시노드 dist[i][j] 
// i = 0  시작
// 1, 2 경유
int disArr[3][MAXN];

// N : 정점의 개수, E : 간선의 개수
// U: 현재 노드, V : 이웃 노드, dist : 거리
// V1, V2 필수 정점
int N, E, U, V, dist, V1, V2;

int result = 0;

void Dijkstra(int start, int number)
{
   // 임시배열 초기화
   for (int i = 1; i <= N; i++) disArr[number][i] = INF;
   // 우선순위 큐에 삽입.
   myPQ.push({ 0, start }); // < first : 거리 , second : 노드 인덱스 >

   disArr[number][start] = 0;

   while (!myPQ.empty()) {
       // -를 붙이는 이유는 우선순위 큐를 이용하여 정렬하기 위함이다.
       // (최소힙으로 구현)
       int nCost = -myPQ.top().first;
       int now = myPQ.top().second;
       myPQ.pop();
       // 해당 노드에서 연결된 모든 경로를 확인
       for (int i = 0; i < graph[now].size(); i++) {
           // 0이라면 길이 없다는 의미 continue
           if (graph[now][i].second == 0) continue;
           // disSum = 임시 노드 + 현재 노드에서 i로가는 비용
           int disSum = nCost + graph[now][i].second;
           // 비용이 더 작다면 최단경로 테이블 값을 갱신.
           if (disSum < disArr[number][graph[now][i].first]) {
               // 임시 노드 업데이트
               disArr[number][graph[now][i].first] = disSum;
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

   // N 정점의 개수, E 간선의 개수를 입력받는다.
   cin >> N >> E;

   for (int i = 0; i < E; i++) {
       cin >> U >> V >> dist;

       // 양방향
       graph[U].push_back(make_pair(V, dist));
       graph[V].push_back(make_pair(U, dist));
   }

   // V1, V2 필수 정점을 입력받는다.
   cin >> V1 >> V2;

   Dijkstra(1, 0);
   Dijkstra(V1, 1);
   Dijkstra(V2, 2);

   // 1 -> V1 -> V2 -> N 과 1 -> V2 -> V1 -> N 을 비교
   result = min(disArr[0][V2] + disArr[2][V1] + disArr[1][N], disArr[0][V1] + disArr[1][V2] + disArr[2][N]);

   // 1 -> N 으로 가는 경우 또는 
   if (disArr[0][N] == INF || disArr[1][V2] == INF) cout << -1;
   else cout << result;

   return 0;
}