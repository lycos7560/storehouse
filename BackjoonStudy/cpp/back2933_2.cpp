#include<iostream>
#include<list>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;

//RC�� ���� ����
constexpr auto MAX = 102;

char map[MAX][MAX];
bool mapCheck[MAX][MAX];

// 0 �� , 1 ��, 2 �� , 3 ��
int dy[4] = { 1, 0, 0, -1 };
int dx[4] = { 0, -1, 1, 0 };


// true ��, false ��
bool leftRight;
int R, C, N;
list<int> heightList;
list<int>::iterator iterList;

//Ŭ�������� ��ġ�� �������ش�.
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
/// ���� �ʱ�ȭ�մϴ�.
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
/// ������ ���ǿ� ���߾ ���� �����մϴ�.
/// </summary>
void SettingMap()
{
   cin >> R >> C;

   // �̳׶��� ��ġ�� ����
   for (int y = R; y >= 1; y--)
   {
       for (int x = 1; x <= C; x++)
       {
           cin >> map[y][x];
       }
   }

   cin >> N;
   int temp;
   /// ���� Ƚ���� ���̸� ����
   while (N > 0)
   {
       cin >> temp;
       heightList.push_back(temp);
       N--;
   }

}


/// <summary>
/// �ð������� ���� Ȯ���ϱ� ����
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
/// �ٴڰ� ����� �̳׶��� BFS�� �˻��Ͽ� �湮ó���� ���ش�.
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
       // �� �� �� üũ

       for (int i = 0; i < 4; i++)
       {
           dydxPair = tempPair;
           dydxPair.first += dy[i];
           dydxPair.second += dx[i];

           // ������ ����ų� �湮ó���� �Ȱ� �Ǵ� ����̸� �Ѿ��.
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

/// �ٴڰ� ����� �̳׶��� ã�´�.
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
/// �⺻���� ������ �ʱ�ȭ�մϴ�.
/// </summary>
void Initialization()
{
   ResetMap();
   SettingMap();
}


/// <summary>
/// ��/�� ���� ����⸦ ������ �̳׶��� �ִ��� Ȯ�� �մϴ�.
/// </summary>
void ThrowStickFromSideToSide()
{

   switch (leftRight)
   {
   case true:
       for (int x = 1; x <= C; x++)
       {
           // ���� �̳׶��� �ִٸ�
           if (map[*iterList][x] == 'x')
           {
               // �ش� �̳׶��� �� �������� �ٲپ� �ش�.
               map[*iterList][x] = '.';
               break;
           }
       }
       break;

   case false:
       for (int x = C; x > 0; x--)
       {
           // ���� �̳׶��� �ִٸ�
           if (map[*iterList][x] == 'x')
           {
               // �ش� �̳׶��� �� �������� �ٲپ� �ش�.
               map[*iterList][x] = '.';
               break;
           }
       }
       break;

   default:
       cout << "bool �ε� �̰� ��µǸ� ���� �ȵ�";
       break;
   }
   resetCheck();
   // �¿츦 �ٲپ� �ݴϴ�.
   leftRight = !leftRight;
}

void BFS(int y, int x)
{
   // Ŭ������ ����Ʈ �ʱ�ȭ
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

       // ���߿� ���ִ� Ŭ�����͵��� ����Ʈ
       clusterList.push_back(tempPair);

       // �� �� �� üũ
       for (int i = 0; i < 4; i++)
       {
           dydxPair = tempPair;
           dydxPair.first += dy[i];
           dydxPair.second += dx[i];

           // ������ ����ų� �湮ó���� �Ȱ� �Ǵ� ����̸� �Ѿ��.
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
   // �ٴڿ� ���� �̳׶��� �湮ó���� �Ǿ��ִ�.
   // ���߿� �̳׶��� ���� ��ġ�� �ٴ� �Ǵ� �̳׶� �̶�� �극��ũ 
   while (!check && !clusterList.empty())
   {
       if (!check)
       {
           count++;
       }

       // Ŭ�����Ͱ� ��� ������ �� �ִ� �� Ȯ���մϴ�. 
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

   // ���� �������� �ִٸ�
   if (count > 0)
   {
       // �ʿ��� Ŭ�����͸� �ð������� �������ְ�
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

   // ���� ����Ʈ ��ŭ ��ȸ(����Ʈ�� ũ�� = ����⸦ ���� Ƚ��)
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