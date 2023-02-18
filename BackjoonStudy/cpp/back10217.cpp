#pragma warning(disable:6385)
#pragma warning(disable:6262)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

priority_queue<tuple<long long int, int, int>> myPQ;

long long int disArr[101][10001];

constexpr long long int INF = INT64_MAX;

int T, N, M, K, U, V, C, D, cnt;

long long int Dijstra()
{
   cin >> N >> M >> K;

   // ���ͽ�Ʈ�� �迭 �ʱ�ȭ
   for (int i = 0; i <= N; i++)
       for (int j = 0; j <= M; j++)
           disArr[i][j] = INF;

   vector<tuple<int, int, int>> graph[10000];

   for (int i = 0; i < K; i++) {
       cin >> U >> V >> C >> D;
       graph[U].push_back(make_tuple(V, C, D));
   }

   // �켱���� ť�� ����.
   myPQ.push({ 0, 1, 0 }); // <�Ÿ� , ��� �ε��� , ���>

   disArr[1][0] = 0;

   while (!myPQ.empty()) {
       // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
       // (�ּ������� ����)
       long long int nCost = -get<0>(myPQ.top()); // ���� �ִ� �Ÿ�

       int now = get<1>(myPQ.top()); // ���� ���

       int money = get<2>(myPQ.top()); // ��� 

       myPQ.pop();

       // �̹� ��� �ִ� �ͺ��� �Ÿ��� ũ�� �Ѿ��.
       if (disArr[now][money] < nCost) continue;

       // �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {

           // ����� ������ �ʰ��ȴٸ� continue
           if (money + get<1>(graph[now][i]) > M) continue;

           // disSum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           long long int disSum = nCost + get<2>(graph[now][i]);

           // ����� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           if (disSum < disArr[get<0>(graph[now][i])][money + get<1>(graph[now][i])]) {
               // �ӽ� ��� ������Ʈ
               disArr[get<0>(graph[now][i])][money + get<1>(graph[now][i])] = disSum;
               // �켱���� ť�� (�Ÿ�, ��� �ε���, ���) Ǫ��
               myPQ.push({ -disSum, get<0>(graph[now][i]), money + get<1>(graph[now][i]) });

           }
       }
   }

   long long int result = INF;

   for (int i = 0; i <= M; i++) {
      result = min(disArr[N][i], result);
   }

   return result;
}


int main()
{
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(NULL);
   std::cout.tie(NULL);

   cin >> T;

   while (T-- > 0) {
       long long int result = Dijstra();
       if (result == INF) cout << "Poor KCM\n";
       else cout << result << "\n";
   }

   return 0;
}

