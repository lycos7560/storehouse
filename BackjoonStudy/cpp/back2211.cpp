#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// N(1 ≤ N ≤ 1,000)개의 컴퓨터
constexpr int MAXN = 1001;
constexpr int INF = INT32_MAX;

///*
//각 노드에 연결되어 있는 노드에 대한 정보를 담는 벡터
//a번 노드에서 b번 노드로 가는 비용이 c라는 의미
//graph[a].push_back((make_pair(B, C));
//*/
vector<pair<int, int>> graph[MAXN];

// Dijkstra 알고리즘에 사용할 우선순위 큐
priority_queue<pair<int, int>> myPQ;

// 문제의 결과를 출력하기 위한 map 
map<int, int> myMap;

// dist[i][j]  
// => i 에서 j 까지의 최단거리 (임시 노드)
int timeArr[MAXN];

// dist[i][j]  
// => i 에서 j 까지의 최단거리 (임시 노드)
int cntArr[MAXN];

// N : 정점의 개수, M : 간선의 개수
// U: 현재 노드, V : 이웃 노드, t : 통신 시간
int N, M, U, V, t;


void Dijkstra(int start)
{
   // 임시배열 초기화
   for (int i = 1; i <= N; i++) timeArr[i] = INF;
   // 우선순위 큐에 삽입.
   myPQ.push({ 0, start }); // < first : 거리 , second : 노드 인덱스 >
   timeArr[start] = 0;

   while (!myPQ.empty()) {
       // -를 붙이는 이유는 우선순위 큐를 이용하여 정렬하기 위함이다.
       // (최소힙으로 구현)
       int nCost = -myPQ.top().first;
       int now = myPQ.top().second;
       myPQ.pop();

       // 이미 담겨 있는 것보다 거리가 크면 넘어간다.
       if (timeArr[now] < nCost) continue;

       // 해당 노드에서 연결된 모든 경로를 확인
       for (int i = 0; i < graph[now].size(); i++) {
           // 0이라면 길이 없다는 의미 continue
           if (graph[now][i].second == 0) continue;
           // disSum = 임시 노드 + 현재 노드에서 i로가는 비용
           int disSum = nCost + graph[now][i].second;
           // 비용이 더 작다면 최단경로 테이블 값을 갱신.
           if (disSum < timeArr[graph[now][i].first]) {
               // 임시 노드 업데이트
               timeArr[graph[now][i].first] = disSum;
               // 우선순위 큐에 (거리, 노드 인덱스) 푸시
               myPQ.push(make_pair(-disSum, graph[now][i].first));

               // 만약 map의 key 값이 겹친다면 해당 값을 지운다.
               if (myMap.count(graph[now][i].first)) myMap.erase(graph[now][i].first);
               // 도착지를 Key 값으로 map에 저장
               myMap.insert(make_pair(graph[now][i].first, now));
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

   cin >> N >> M;

   for (int i = 0; i < M; i++) {
       cin >> U >> V >> t;
       // 양방향 통신 가능
       graph[U].push_back(make_pair(V, t));
       graph[V].push_back(make_pair(U, t)); 
   }

   Dijkstra(1);

   // map의 사이즈를 출력합니다.
   cout << myMap.size() << "\n";

   // 복구한 회선을 출력
   for (auto it = myMap.begin(); it != myMap.end(); it++) 
       cout << it->first << " " << it->second << "\n";

	return 0;
}
