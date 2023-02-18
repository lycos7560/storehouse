#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int INF = INT32_MAX;

int disArr[501];

priority_queue<pair<int, int>> mypq;

vector<pair<int, int>> graph[10001];

vector<int> trace[501];

int N, M, S, D, U, V, P;

void MyDijstra()
{  
   for (int i = 0; i <= N; i++) disArr[i] = INF;

   for (int i = 0; i < M; i++) {
       cin >> U >> V >> P;
       graph[U].push_back(make_pair(V, P));
   }

   // 우선순위 큐에 삽입.
   mypq.push({ 0, S }); // < first : 거리 , second : 노드 인덱스 >

   disArr[S] = 0;

   while (!mypq.empty()) {
       // -를 붙이는 이유는 우선순위 큐를 이용하여 정렬하기 위함이다.
       // (최소힙으로 구현)
       int ncost = -mypq.top().first;
       int now = mypq.top().second;

       mypq.pop();

       // 이미 담겨 있는 것보다 거리가 크면 넘어간다.
       if (disArr[now] < ncost) continue;

       // 해당 노드에서 연결된 모든 경로를 확인
       for (int i = 0; i < graph[now].size(); i++) {
           // dissum = 임시 노드 + 현재 노드에서 i로가는 비용
           int dissum = ncost + graph[now][i].second;
           // 비용이 더 작다면 최단경로 테이블 값을 갱신.
           // 같아도 확인이 필요하다.
           // 최소 거리가 여러개 있을 수 있기 떄문
           if (dissum <= disArr[graph[now][i].first]) {

               if (dissum < disArr[graph[now][i].first]) {
               
                   // 임시 노드 업데이트
                   disArr[graph[now][i].first] = dissum;

                   trace[graph[now][i].first].clear(); // 새로 갱신한다면 전에 있던 것이 필요가 없다.
                   trace[graph[now][i].first].push_back(now); // 경로를 저장

                   // 우선순위 큐에 (거리, 노드 인덱스) 푸시
                   mypq.push(make_pair(-dissum, graph[now][i].first));
               }
               else trace[graph[now][i].first].push_back(now); // 경로를 저장   
           }
       }
   }

   // 최단 거리의 경로를 삭제해 줍니다.
   queue<int> delQ;
   delQ.push(D);
   while (!delQ.empty()) {
       int nowDel = delQ.front();
       delQ.pop();
       for (int i = 0; i < trace[nowDel].size(); i++) {
           for (auto it = graph[trace[nowDel][i]].begin(); it != graph[trace[nowDel][i]].end(); it++) {
               if ((*it).first == nowDel) {
                   delQ.push(trace[nowDel][i]);
                   graph[trace[nowDel][i]].erase(it);
                   break;
               }
           }
       }
   }


   // 새로운 데이크스트라를 진행하여 거의 최단 경로를 찾는다.
   for (int i = 0; i <= N; i++) disArr[i] = INF;
   // 우선순위 큐에 삽입.
   mypq.push({ 0, S }); // first : 거리 , second : 노드 인덱스
   disArr[S] = 0;
   while (!mypq.empty()) {
       // -를 붙이는 이유는 우선순위 큐를 이용하여 정렬하기 위함이다.
       // (최소힙으로 구현)
       int ncost = -mypq.top().first;
       int now = mypq.top().second;

       mypq.pop();

       // 이미 담겨 있는 것보다 거리가 크면 넘어간다.
       if (disArr[now] < ncost) continue;

       // 해당 노드에서 연결된 모든 경로를 확인
       for (int i = 0; i < graph[now].size(); i++) {
           // dissum = 임시 노드 + 현재 노드에서 i로가는 비용
           int dissum = ncost + graph[now][i].second;
           // 비용이 더 작다면 최단경로 테이블 값을 갱신.
           if (dissum < disArr[graph[now][i].first]) {

               disArr[graph[now][i].first] = dissum;
               // 우선순위 큐에 (거리, 노드 인덱스) 푸시
               mypq.push(make_pair(-dissum, graph[now][i].first));
           }
       }
   }

   for (int i = 0; i <= N; i++) trace[i].clear();
   for (int i = 0; i <= M; i++) graph[i].clear();
}


int main()
{
   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   //cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(NULL);
   std::cout.tie(NULL);

   while (true) {

       cin >> N >> M;

       if (N == 0 && M == 0) break;

       cin >> S >> D;

       MyDijstra();

       if (disArr[D] == INF) cout << -1 << "\n";
       else cout << disArr[D] << "\n";
   }

   return 0;
}