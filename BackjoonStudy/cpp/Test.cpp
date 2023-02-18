#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <tuple>
#include <map>

using namespace std;

constexpr int inf = int32_max;

int disarr[502];

bool check[502][502];

int n, m, s, d, u, v, p;

int dijstra()
{
   int result = inf;

   memset(disarr, inf, sizeof disarr);

   memset(check, false, sizeof check);

   priority_queue<tuple<int, int, list<pair<int, int>>>> firstpq;

   vector<pair<int, int>> graph[10001];

   list<pair<int, int>> mylist;

   multimap<int, list<pair<int, int>>> mymap;

   for (int i = 0; i < m; i++) {
       cin >> u >> v >> p;
       graph[u].push_back(make_pair(v, p));
   }

   // 우선순위 큐에 삽입.
   firstpq.push({ 0, s, mylist }); // < first : 거리 , second : 노드 인덱스 >
   disarr[s] = 0;
   while (!firstpq.empty()) {
       // -를 붙이는 이유는 우선순위 큐를 이용하여 정렬하기 위함이다.
       // (최소힙으로 구현)
       int ncost = -get<0>(firstpq.top());
       int now = get<1>(firstpq.top());
       mylist = get<2>(firstpq.top());
       firstpq.pop();

       // 이미 담겨 있는 것보다 거리가 크면 넘어간다.
       if (disarr[now] < ncost) continue;

       // 해당 노드에서 연결된 모든 경로를 확인
       for (int i = 0; i < graph[now].size(); i++) {
           list<pair<int, int>> templist = mylist;
           // dissum = 임시 노드 + 현재 노드에서 i로가는 비용
           int dissum = ncost + graph[now][i].second;

           // 비용이 더 작다면 최단경로 테이블 값을 갱신.
           if (dissum <= disarr[graph[now][i].first]) {

               templist.push_back(make_pair(now, graph[now][i].first));


               if (dissum < disarr[graph[now][i].first])
               {
                   // 임시 노드 업데이트
                   disarr[graph[now][i].first] = dissum;
                   // 우선순위 큐에 (거리, 노드 인덱스) 푸시
                   firstpq.push(make_tuple(-dissum, graph[now][i].first, templist));

               }

               if (graph[now][i].first == d && result >= dissum) {
                   result = dissum;
                   mymap.insert(make_pair(dissum, templist));
               }

           }
       }
   }

   result = disarr[d];

   for (auto mit = mymap.begin(); mit != mymap.end(); mit++) {
       if (result == mit->first) {
           for (auto it = mit->second.begin(); it != mit->second.end(); it++) {
               check[it->first][it->second] = true;
           }
       }

       else break;
   }

   priority_queue<pair<int, int>> mypq;

   memset(disarr, inf, sizeof disarr);

   // 우선순위 큐에 삽입.
   mypq.push({ 0, s }); // < first : 거리 , second : 노드 인덱스 >
   disarr[s] = 0;

   while (!mypq.empty()) {
       // -를 붙이는 이유는 우선순위 큐를 이용하여 정렬하기 위함이다.
       // (최소힙으로 구현)
       int ncost = -mypq.top().first;
       int now = mypq.top().second;
       mypq.pop();

       // 이미 담겨 있는 것보다 거리가 크면 넘어간다.
       if (disarr[now] < ncost) continue;
       // 해당 노드에서 연결된 모든 경로를 확인
       for (int i = 0; i < graph[now].size(); i++) {
           if (check[now][graph[now][i].first] == true) continue;
           // dissum = 임시 노드 + 현재 노드에서 i로가는 비용
           int dissum = ncost + graph[now][i].second;
           // 비용이 더 작다면 최단경로 테이블 값을 갱신.
           if (dissum < disarr[graph[now][i].first]) {
               // 임시 노드 업데이트
               disarr[graph[now][i].first] = dissum;
               // 우선순위 큐에 (거리, 노드 인덱스) 푸시
               mypq.push(make_pair(-dissum, graph[now][i].first));
           }
       }
   }

   return disarr[d];
}


int main()
{
   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   //cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(null);
   std::cout.tie(null);

   while (true) {

       cin >> n >> m;

       if (n == 0 && m == 0) break;

       cin >> s >> d;

       int result = dijstra();

       if (result == inf) cout << -1 << "\n";
       else cout << result << "\n";
   }



   return 0;
}