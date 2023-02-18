#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

// 최대 범위 
constexpr int MAX = 20;

// 상/좌/우/하
int dxdy[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

pair<int, int> Shark; // 상어 크기, 경험치?

tuple<int, int, int> posShark; // 상어의 x, y위치 / 시간

tuple<int, int, int> tempT;

int N, dx, dy;

int map[MAX][MAX]; // 맵

bool eatMap[MAX][MAX]; // 먹을 수 있는 물고기 체크

bool mapCheck[MAX][MAX]; // BFS 방문 체크에 사용

// BFS 탐색, 반환값음 상어의 위치와 시간
tuple<int, int, int> SharkBFS()
{
   queue<tuple<int, int, int>> myQ;

   // 방문처리 초기화
   fill(&mapCheck[0][0], &mapCheck[N - 1][N], false);
   fill(&eatMap[0][0], &eatMap[N - 1][N], false);

   myQ.push(posShark);
   mapCheck[get<0>(posShark)][get<1>(posShark)] = true;

   int dis = 99999;
   while (!myQ.empty()) {
       tempT = myQ.front();
       myQ.pop();

       // 상/하/좌/우를 탐색하기 위한 반복문
       for (int i = 0; i < 4; i++) {
           dx = get<0>(tempT) + dxdy[i][0];
           dy = get<1>(tempT) + dxdy[i][1];

           // 문제의 범위를 벗어나는 경우 => 넘어간다.
           if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
           // 이미 방문한 곳 일 경우와 해당 칸의 물고기가 상어보다 클 경우 => 넘어간다.
           if (mapCheck[dx][dy] == true || map[dx][dy] > Shark.first) continue;

           // 상어가 더 크고, 빈 공간이 아니라면 
           if (map[dx][dy] < Shark.first && map[dx][dy] != 0 ) {

               if (get<2>(tempT) + 1 <= dis) {
                   eatMap[dx][dy] = true;
                   dis = get<2>(tempT) + 1;
               }
           }

           mapCheck[dx][dy] = true; // 방문처리
           myQ.push(make_tuple(dx, dy, get<2>(tempT) + 1)); // 탐색 Q에 넣기
       }
   }

   // 먹을 수 있는 물고기들 중에서 
   // 가장 위, 좌측에 있는 물고기를 선택한다.
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           if (eatMap[i][j] == true) {
               Shark.second++;
               map[i][j] = 0;
               if (Shark.first == Shark.second) {
                   Shark.first++;
                   Shark.second = 0;
               }

               return make_tuple(i, j, dis);
           }
       }
   }
   
   // 없다면 기존 상어의 위치를 반환한다.
   return posShark;
}


int main()
{
   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(NULL);
   cout.tie(NULL);

   Shark = make_pair(2, 0);

   cin >> N;
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           cin >> map[i][j];
           if (map[i][j] == 9) { // 상어의 위치를 저장
               posShark = make_tuple(i, j, 0);
               map[i][j] = 0;
           }
       }
   }

   bool check = true;
   while (check) {
       check = false;
       for (int i = 0; i < N && !check; i++) {
           for (int j = 0; j < N && !check; i++) {
               if (map[i][j] >= 1) check = true;
           }
       }

       tempT = SharkBFS();
       
       // BFS 탐색 후에도 상어의 움직임이 없다면 먹을 수 있는 물고기가 없다.
       if (get<2>(tempT) == get<2>(posShark)) break;
       else posShark = tempT;
 
   }

   cout << get<2>(posShark);

	return 0;
}
