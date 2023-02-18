#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

constexpr int MAX = 100;

// N 세로, M 가로, H 높이
int N, M, H, dx, dy, dz, maxCnt = 0;

// N, M의 범위 
int map[MAX][MAX][MAX];

// BFS 방문처리
bool mapCheck[MAX][MAX][MAX];

// 탐색하는 방향 설정
int dxdydz[6][3] = { 
        {0, 0, 1},
        {0, 0, -1},
        {1, 0, 0},
        {-1, 0, 0},
        {0, 1, 0},
        {0, -1, 0}
};

queue<tuple<int, int, int>> myQueue;

tuple<int, int, int> tempTuple;

bool falseCheck = true;

int main()
{
   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> M >> N >> H;


   for (int k = 0; k < H; k++) {
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < M; j++) {              
                   cin >> map[i][j][k];    
           }
       }
   }

   for (int  k = 0; k < H; k++) {
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < M; j++) {
               if (map[i][j][k] == 1) { // 익은 토마토를 큐에 넣고 방문처리
                   mapCheck[i][j][k] = true;
                   map[i][j][k] = 0; // map[i][j][k] = 익은 날짜
                   myQueue.push(make_tuple(i, j, k));
               }
           }
       }
   }


   while (!myQueue.empty()) {

       tempTuple = myQueue.front();
       myQueue.pop();
       // 상/하/좌/우를 탐색하기 위한 반복문
       for (int i = 0; i < 6; i++) {
           dx = get<0>(tempTuple) + dxdydz[i][0];
           dy = get<1>(tempTuple) + dxdydz[i][1];
           dz = get<2>(tempTuple) + dxdydz[i][2];


           // 문제의 범위를 벗어나는 경우 => 넘어간다.
           if (dx < 0 || dy < 0 || dz < 0 || dx >= N || dy >= M || dz >= H) continue;
           // '-1' 인 경우, 이미 방문한 곳 일 경우 => 넘어간다.
           if (mapCheck[dx][dy][dz] == true || map[dx][dy][dz] == -1) continue;

           map[dx][dy][dz] = map[get<0>(tempTuple)][get<1>(tempTuple)][get<2>(tempTuple)] + 1; // 카운트를 올려준다.
           mapCheck[dx][dy][dz] = true; // 방문처리
           myQueue.push(make_tuple(dx, dy, dz));
       }
   }

   for (int k = 0; k < H && falseCheck; k++) {
       for (int i = 0; i < N && falseCheck; i++) {
           for (int j = 0; j < M && falseCheck; j++) {
                   maxCnt = max(maxCnt, map[i][j][k]); // 날짜 출력
                   // 익지 않은 토마토가 방문처리가 안되어있다면 막혀있다는 뜻 
                   if (map[i][j][k] == 0 && mapCheck[i][j][k] == false)  falseCheck = false;
           }
       }
   }

   // 익지 않은 토마토가 있다면 -1 출력
   // 없다면 날짜 출력
   if (falseCheck) cout << maxCnt;
   else cout << -1;

   return 0;
}