#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAXN = 3000;

constexpr long long int INF = INT64_MAX;
constexpr long long int uINF = INT64_MIN;

int N, M, K;

int V1, V2, d;

vector<pair<int, int>> graph[MAXN];

vector<int> fCity;

int main()
{
   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N >> M >> K;

   for (int i = 0; i < M; i++) {
       cin >> V1 >> V2 >> d;
       // 양방향 그래프
       graph[V1].push_back(make_pair(V2, d));
       graph[V2].push_back(make_pair(V1, d));
   }
    
   for (int i = 0; i < K; i++) {
       cin >> d;
       fCity.push_back(d);
   }

   return 0;

}