#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAXN = 1001;
constexpr int INF = INT32_MAX;

// N : ������ ��, M : �ܹ��� ������ ����, X : ��Ƽ�� ��ġ
int N, M, X;

// U : ���� ���, V : �̿� ���, dist : �Ÿ�
int U, V, dist;

int cnt = 1;

bool debug = false;

int result[MAXN];

/*
�� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� ����
a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
graph[a].push_back((make_pair(B, C));
*/
vector<pair<int, int>> graph[MAXN];

// dist[i][j]  => i ���� j ������ �ִܰŸ� (�ӽ� ���)
int disArr[MAXN][MAXN];

// �켱 ���� ť��
// �ӽ� �Ÿ��� ���� ��带 ȿ�������� �����ϴ� �� ���
// <�Ÿ�, ��� �ε���>
priority_queue<pair<int, int>> myPQ;

int main()
{
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N >> M >> X;
   
   // ���� �Է¹ޱ�
   for (int i = 0; i < M; i++) {
       cin >> U >> V >> dist;
       graph[U].push_back(make_pair(V, dist));
   } 

   while (cnt <= N) {

       // �ӽù迭 �ʱ�ȭ
       for (int i = 1; i <= N; i++)    disArr[cnt][i] = INF;
       
       // �켱���� ť�� ����.
       myPQ.push({ 0, cnt }); // < first : �Ÿ� , second : ��� �ε��� >
       disArr[cnt][cnt] = 0; 

       while (!myPQ.empty()) {
           // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
           // (�ּ������� ����)
           int nCost = -myPQ.top().first;
           int now = myPQ.top().second;
           myPQ.pop();
           // �ش� ��忡�� ����� ��� ��θ� Ȯ��
           for (int i = 0; i < graph[now].size(); i++) {
               // 0�̶�� ���� ���ٴ� �ǹ� continue
               if (graph[now][i].second == 0) continue;
               // disSum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
               int disSum = nCost + graph[now][i].second;
               // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
               if (disSum < disArr[cnt][graph[now][i].first]) {
                   // �ӽ� ��� ������Ʈ
                   disArr[cnt][graph[now][i].first] = disSum;
                   // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
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
               cout << j << " -> " << i << " �� �ּ� �Ÿ� " << disArr[j][i] << " \n";
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