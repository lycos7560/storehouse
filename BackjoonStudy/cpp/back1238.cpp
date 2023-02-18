#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAXN = 1001;
constexpr int INF = INT32_MAX;

// N : 마을의 수, M : 단방향 도로의 개수, X : 파티의 위치
int N, M, X;

// U : 현재 노드, V : 이웃 노드, dist : 거리
int U, V, dist;

int cnt = 1;

bool debug = false;

int result[MAXN];

/*
각 노드에 연결되어 있는 노드에 대한 정보를 담는 벡터
a번 노드에서 b번 노드로 가는 비용이 c라는 의미
graph[a].push_back((make_pair(B, C));
*/
vector<pair<int, int>> graph[MAXN];

// dist[i][j]  => i 에서 j 까지의 최단거리 (임시 노드)
int disArr[MAXN][MAXN];

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

   cin >> N >> M >> X;
   
   // 간선 입력받기
   for (int i = 0; i < M; i++) {
       cin >> U >> V >> dist;
       graph[U].push_back(make_pair(V, dist));
   } 

   while (cnt <= N) {

       // 임시배열 초기화
       for (int i = 1; i <= N; i++)    disArr[cnt][i] = INF;
       
       // 우선순위 큐에 삽입.
       myPQ.push({ 0, cnt }); // < first : 거리 , second : 노드 인덱스 >
       disArr[cnt][cnt] = 0; 

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
               if (disSum < disArr[cnt][graph[now][i].first]) {
                   // 임시 노드 업데이트
                   disArr[cnt][graph[now][i].first] = disSum;
                   // 우선순위 큐에 (거리, 노드 인덱스) 푸시
                   myPQ.push(make_pair(-disSum, graph[now][i].first));
               }
           }
       }

       cnt++;
   }

   if (debug) {
       for (int j = 1; j <= N; j++) {
           cout << "\n";
           for (int i = 1; i <= N; i++) {
               cout << j << " -> " << i << " 의 최소 거리 " << disArr[j][i] << " \n";
           }
           cout << "\n";
       }
   }


   for (int i = 1; i <= N; i++) {
       result[i] = disArr[X][i] + disArr[i][X];
       result[0] = max(result[i], result[0]);
   }

   cout << result[0];

	return 0;
}