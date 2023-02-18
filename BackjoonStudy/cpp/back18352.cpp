#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int INF = INT_MAX;
constexpr int MAXN = 300000;

// 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
int N, M, K, X;

pair<int, int> temp;

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


   // 정점의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
   cin >> N >> M >> K >> X;

   // 모든 도로의 정보를 입력받기
   for (int i = 0; i < M; i++) {
       int A, B, C;
       cin >> A >> B >> C;
       // A -> B :  C
       graph[A].push_back({ B, C });
   }

   // 임시 노드를 모두 무한으로 초기화
   fill(dist, dist + MAXN, INF);

   // 우선순위 큐에 삽입.
   myPQ.push({ 0, X }); // < first : 거리 , second : 노드 인덱스 >
   dist[X] = 0; // 시작 노드 가기위한 최단 경로는 0으로 설정

   while (!myPQ.empty()) {

       temp = myPQ.top();
       myPQ.pop();

       // 임시 노드의 값보다 노드까지의 비용이 크다면 
       // 이미 체크한 노드
       // 예를 들어 A의 임시노드가 5 / B -> A : 6 
       // 이미 최단 경로를 체크됨
       if (dist[temp.second] < temp.first) continue;

       // 해당 노드에서 연결된 경로를 확인
       for (int i = 0; i < graph[temp.second].size(); i++) {

           // disSum = 임시 노드 + 현재 노드에서 i로가는 비용
           int disSum = temp.first + graph[temp.second][i].second;

           // 비용이 더 작다면 최단경로 테이블 값을 갱신.
           if (disSum < dist[graph[temp.second][i].first])
           {
               // 임시 노드 업데이트
               dist[graph[temp.second][i].first] = disSum;
               // 우선순위 큐에 (거리, 노드 인덱스) 푸시
               myPQ.push(make_pair(disSum, graph[temp.second][i].first));
           }
       }

   }

   // 모든 노드로 가기 위한 최단 거리를 출력
   for (int i = 1; i <= N; i++)
   {
       // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
       if (dist[i] == INF) {
           cout << "INFINITY" << '\n';
       }
       // 도달할 수 있는 경우 거리를 출력
       else {
           cout << dist[i] << '\n';
       }
   }



   return 0;
}
