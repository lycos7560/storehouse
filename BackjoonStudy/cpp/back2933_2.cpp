#include<iostream>
#include<list>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;

//RC의 범위 지정
constexpr auto MAX = 102;

char map[MAX][MAX];
bool mapCheck[MAX][MAX];

// 0 상 , 1 좌, 2 우 , 3 하
int dy[4] = { 1, 0, 0, -1 };
int dx[4] = { 0, -1, 1, 0 };


// true 좌, false 우
bool leftRight;
int R, C, N;
list<int> heightList;
list<int>::iterator iterList;

//클러스터의 위치를 저장해준다.
list<pair<int, int>> clusterList;
list<pair<int, int>>::iterator iterClusterList;


void resetCheck()
{
   for (int x = 1; x <= R; x++)
   {
       for (int y = 1; y <= C; y++)
       {
           mapCheck[x][y] = false;
       }
   }
}


/// <summary>
/// 맵을 초기화합니다.
/// </summary>
void ResetMap()
{
   leftRight = true;
   for (int x = 1; x < MAX; x++)
   {
       for (int y = 1; y < MAX; y++)
       {
           map[x][y] = '.';
           mapCheck[x][y] = false;
       }
   }
}


/// <summary>
/// 문제의 조건에 맞추어서 맵을 셋팅합니다.
/// </summary>
void SettingMap()
{
   cin >> R >> C;

   // 미네랄의 위치를 설정
   for (int y = R; y >= 1; y--)
   {
       for (int x = 1; x <= C; x++)
       {
           cin >> map[y][x];
       }
   }

   cin >> N;
   int temp;
   /// 던진 횟수와 높이를 설정
   while (N > 0)
   {
       cin >> temp;
       heightList.push_back(temp);
       N--;
   }

}


/// <summary>
/// 시각적으로 맵을 확인하기 위함
/// </summary>
void PringMapForDebug()
{
   for (int y = R; y >= 1; y--)
   {

       for (int x = 1; x <= C; x++)
       {
           cout << map[y][x];
       }
       cout << "\n";
   }
}

/// <summary>
/// 바닥과 연결된 미네랄을 BFS로 검색하여 방문처리를 해준다.
/// </summary>
void ConnectFloorBFS(int y, int x)
{
   pair<int, int> tempPair;

   tempPair.first = y;
   tempPair.second = x;
   queue<pair<int, int>> myQueue;
   mapCheck[tempPair.first][tempPair.second] = true;
   myQueue.push(tempPair);

   while (!myQueue.empty())
   {
       tempPair = myQueue.front();
       myQueue.pop();

       pair<int, int> dydxPair;
       // 상 좌 우 체크

       for (int i = 0; i < 4; i++)
       {
           dydxPair = tempPair;
           dydxPair.first += dy[i];
           dydxPair.second += dx[i];

           // 범위를 벗어나거나 방문처리가 된곳 또는 빈곳이면 넘어간다.
           if (dydxPair.first > R || dydxPair.first <= 0 || dydxPair.second <= 0 || dydxPair.second > C
               || mapCheck[dydxPair.first][dydxPair.second] == true || map[dydxPair.first][dydxPair.second] == '.')
           {
               continue;
           }

           mapCheck[dydxPair.first][dydxPair.second] = true;
           myQueue.push(dydxPair);
       }
   }
}

/// 바닥과 연결된 미네랄을 찾는다.
void CheckClusterAssociatedFloor()
{
   for (int x = 1; x <= C; x++)
   {
       if (map[1][x] == 'x')
       {
           ConnectFloorBFS(1, x);
       }
   }

}

/// <summary>
/// 기본적인 조건을 초기화합니다.
/// </summary>
void Initialization()
{
   ResetMap();
   SettingMap();
}


/// <summary>
/// 좌/우 에서 막대기를 던져서 미네랄이 있는지 확인 합니다.
/// </summary>
void ThrowStickFromSideToSide()
{

   switch (leftRight)
   {
   case true:
       for (int x = 1; x <= C; x++)
       {
           // 만약 미네랄이 있다면
           if (map[*iterList][x] == 'x')
           {
               // 해당 미네랄을 빈 공간으로 바꾸어 준다.
               map[*iterList][x] = '.';
               break;
           }
       }
       break;

   case false:
       for (int x = C; x > 0; x--)
       {
           // 만약 미네랄이 있다면
           if (map[*iterList][x] == 'x')
           {
               // 해당 미네랄을 빈 공간으로 바꾸어 준다.
               map[*iterList][x] = '.';
               break;
           }
       }
       break;

   default:
       cout << "bool 인데 이거 출력되면 말이 안됨";
       break;
   }
   resetCheck();
   // 좌우를 바꾸어 줍니다.
   leftRight = !leftRight;
}

void BFS(int y, int x)
{
   // 클러스터 리스트 초기화
   clusterList.clear();

   pair<int, int> tempPair;

   tempPair.first = y;
   tempPair.second = x;
   queue<pair<int, int>> myQueue;
   mapCheck[tempPair.first][tempPair.second] = true;
   myQueue.push(tempPair);

   while (!myQueue.empty())
   {
       tempPair = myQueue.front();
       myQueue.pop();
       pair<int, int> dydxPair;

       // 공중에 떠있는 클러스터들의 리스트
       clusterList.push_back(tempPair);

       // 상 좌 우 체크
       for (int i = 0; i < 4; i++)
       {
           dydxPair = tempPair;
           dydxPair.first += dy[i];
           dydxPair.second += dx[i];

           // 범위를 벗어나거나 방문처리가 된곳 또는 빈곳이면 넘어간다.
           if (dydxPair.first > R || dydxPair.first <= 0 || dydxPair.second <= 0 || dydxPair.second > C
               || mapCheck[dydxPair.first][dydxPair.second] == true || map[dydxPair.first][dydxPair.second] == '.')
           {
               continue;
           }

           if (map[dydxPair.first][dydxPair.second] == 'x')
           {
               mapCheck[dydxPair.first][dydxPair.second] = true;
               myQueue.push(dydxPair);
           }
       }
   }
}


void ClusterDown()
{
   for (int y = 1; y <= R; y++)
   {
       for (int x = 1; x <= C; x++)
       {
           if (mapCheck[y][x] == false && map[y][x] == 'x')
           {
               BFS(y, x);
           }
       }
   }

   for (iterClusterList = clusterList.begin(); iterClusterList != clusterList.end(); iterClusterList++)
   {
       mapCheck[iterClusterList->first][iterClusterList->second] = false;
   }

   int count = 0;
   bool check = false;
   // 바닥에 닿은 미네랄은 방문처리가 되어있다.
   // 공중에 미네랄의 다음 위치가 바닥 또는 미네랄 이라면 브레이크 
   while (!check && !clusterList.empty())
   {
       if (!check)
       {
           count++;
       }

       // 클러스터가 몇번 내려갈 수 있는 지 확인합니다. 
       for (iterClusterList = clusterList.begin(); iterClusterList != clusterList.end(); iterClusterList++)
       {
           if ((iterClusterList->first - count) <= 0 || mapCheck[iterClusterList->first - count][iterClusterList->second] == true)
           {
               check = true;
               break;
           }
       }
   }

   count--;

   // 만약 움직임이 있다면
   if (count > 0)
   {
       // 맵에서 클러스터를 시각적으로 제거해주고
       for (iterClusterList = clusterList.begin(); iterClusterList != clusterList.end(); iterClusterList++)
       {
           map[iterClusterList->first][iterClusterList->second] = '.';
       }

       for (iterClusterList = clusterList.begin(); iterClusterList != clusterList.end(); iterClusterList++)
       {
           map[iterClusterList->first - count][iterClusterList->second] = 'x';
       }

   }
}


int main()
{
   Initialization();

   // 높이 리스트 만큼 순회(리스트의 크기 = 막대기를 던진 횟수)
   for (iterList = heightList.begin(); iterList != heightList.end(); iterList++)
   {
       ThrowStickFromSideToSide();
       CheckClusterAssociatedFloor();
       ClusterDown();
   }

   CheckClusterAssociatedFloor();
   PringMapForDebug();

   return 0;
}