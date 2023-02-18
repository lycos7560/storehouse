#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 50;

constexpr long long int INF = -INT64_MAX;

long long int disArr[MAXN];

int N, S, D, M, V, U, W, G[MAXN];

bool check = false;

vector<pair<int, int>> graph[MAXN];

int main()
{
   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(NULL);
   std::cout.tie(NULL);

   cin >> N >> S >> D >> M;

   // 교통 수단을 입력받는다.
   for (int i = 0; i < M; i++) {
       cin >> V >> U >> W;
       // 단방향 교통수단 출발, 도착, 비용
       graph[V].push_back(make_pair(U, -W));
   }

   // 도시에서 버는 비용입력
   for (int i = 0; i < N; i++) cin >> G[i];

   fill(disArr, disArr + MAXN, INF);

   disArr[S] = G[S];

   // N번 이후부터는 순환 체크
   // 순환이 있는지 충분히 확인
   for (int k = 1; k <= N * 2; k++) { 
       for (int i = 0; i < N; i++) { // 시작 정점
           for (int j = 0; j < graph[i].size(); j++) {
               int v = graph[i][j].first; // 도착점
               int weight = graph[i][j].second; // 가중치

               if (disArr[i] == -INF) disArr[v] = -INF; // 출발지가 순환이라면 도착지도 순환
               else if (disArr[i] != INF && disArr[i] + weight + G[v] > disArr[v]) {
                   disArr[v] = disArr[i] + weight + G[v]; // 업데이트

                   if (k >= N) disArr[v] = -INF; // 순환찾기
               }
           }
       }
   }

   if (disArr[D] == -INF) cout << "Gee"; // 순환에 포함
   else if (disArr[D] == INF) cout << "gg"; // 도착 불가능 
   else cout << disArr[D];

   return 0;

}