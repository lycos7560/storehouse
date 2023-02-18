#include <iostream>

using namespace std;

constexpr int MAXN = 101;

bool map[MAXN][MAXN];
bool mapcheck[MAXN][MAXN];

int N, temp;

void check(int start, int end)
{
   mapcheck[start][end] = true;
   map[start][end] = true;

   for (int i = 1; i <= N; i++) {
       if (map[end][i] && !mapcheck[start][i]) {
           check(start, i);
       } 
   } 
}

int main()
{
   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N;

   for (int i = 1; i <= N; i++) {
       for (int j = 1; j <= N; j++) {
           cin >> map[i][j];
       }
   }

   for (int i = 1; i <= N; i++) {
       for (int j = 1; j <= N; j++) {
           if (map[i][j] == true && mapcheck[i][j] != true) {
               mapcheck[i][j] = true;
               check(i, j);
           }
       }
   }

   for (int i = 1; i <= N; i++) {
       for (int j = 1; j <= N; j++) {
           cout << map[i][j] << " ";
       }
       cout << "\n";
   }

	return 0;
}