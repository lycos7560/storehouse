#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAXN = 20001;
constexpr int INF = INT32_MAX;

// Dijkstra 알고리즘에 사용할 우선순위 큐
priority_queue<pair<int, int>> myPQ;

///*
//각 노드에 연결되어 있는 노드에 대한 정보를 담는 벡터
//a번 노드에서 b번 노드로 가는 비용이 c라는 의미
//graph[a].push_back((make_pair(B, C));
//*/
vector<pair<int, int>> graph[MAXN];

// 임시노드
int disArr[MAXN];

// v : 정점의 개수, E : 간선의 개수, K : 시작 노드
// u : 현재 노드, v : 이웃 노드, dist : 거리
int V, E, K, u, v, dist;

void Dijkstra(int start)
{
   // 임시배열 초기화
   for (int i = 1; i <= V; i++) disArr[i] = INF;
   // 우선순위 큐에 삽입.
   myPQ.push({ 0, start }); // < first : 거리 , second : 노드 인덱스 >
   disArr[start] = 0;

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
           if (disSum < disArr[graph[now][i].first]) {
               // 임시 노드 업데이트
               disArr[graph[now][i].first] = disSum;
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
   cin >> V >> E >> K;

   for (int i = 0; i < E; i++) {
       cin >> u >> v >> dist;
       graph[u].push_back(make_pair(v, dist));
   }

   Dijkstra(K);

   // 출력
   for (int i = 1; i <= V; i++) {
       if (disArr[i] == INF) {
           cout << "INF" << "\n";
           continue;
       }

       cout << disArr[i] << "\n";
   }

   return 0;
}