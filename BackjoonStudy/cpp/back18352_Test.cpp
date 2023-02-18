#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

constexpr int INF = INT32_MAX;
constexpr int MAXN = 300001;

// 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
int N, M, K, X;

list<int> myList;

/*
각 노드에 연결되어 있는 노드에 대한 정보를 담는 벡터
a번 노드에서 b번 노드로 가는 비용이 c라는 의미
graph[a].push_back({b, c});
*/
vector< pair<int, int> > graph[MAXN];

// 그래프의 시작 노드에서 서로의 노드까지의 거리를 저장하는 배열 
// 이것은 각 노드에 대한 임시 거리를 추적하는 데 사용됩니다.
// 임시 노드
int dist[MAXN];

// 우선 순위 큐는
// 임시 거리를 가진 노드를 효율적으로 선택하는 데 사용
// <거리, 노드 인덱스>
priority_queue<pair<int, int>> myPQ;

int main()
{
   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(NULL);
   cout.tie(NULL);


   // 정점의 개수 N, 간선의 개수 M, 간선의 정보 K, 출발 정점의 번호 X
   cin >> N >> M >> K >> X;

   // 모든 도로의 정보를 입력받기
   for (int i = 0; i < M; i++) {
       int A, B;
       cin >> A >> B;
       // A -> B :  C
       graph[A].push_back({ B, 1 });
   }

   // 임시 노드를 모두 무한으로 초기화
   fill(dist, dist + MAXN, INF);

   // 우선순위 큐에 삽입.
   myPQ.push({ 0, X }); // < first : 거리 , second : 노드 인덱스 >
   dist[X] = 0; // 시작 노드 가기위한 최단 경로는 0으로 설정

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
           if (disSum < dist[graph[now][i].first]) {
               // 임시 노드 업데이트
               dist[graph[now][i].first] = disSum;
               // 우선순위 큐에 (거리, 노드 인덱스) 푸시
               myPQ.push(make_pair(-disSum, graph[now][i].first));
           }
       }
   }

   // 출력하는 부분
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
