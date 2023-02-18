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
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(NULL);
   std::cout.tie(NULL);

   cin >> N >> S >> D >> M;

   // ���� ������ �Է¹޴´�.
   for (int i = 0; i < M; i++) {
       cin >> V >> U >> W;
       // �ܹ��� ������� ���, ����, ���
       graph[V].push_back(make_pair(U, -W));
   }

   // ���ÿ��� ���� ����Է�
   for (int i = 0; i < N; i++) cin >> G[i];

   fill(disArr, disArr + MAXN, INF);

   disArr[S] = G[S];

   // N�� ���ĺ��ʹ� ��ȯ üũ
   // ��ȯ�� �ִ��� ����� Ȯ��
   for (int k = 1; k <= N * 2; k++) { 
       for (int i = 0; i < N; i++) { // ���� ����
           for (int j = 0; j < graph[i].size(); j++) {
               int v = graph[i][j].first; // ������
               int weight = graph[i][j].second; // ����ġ

               if (disArr[i] == -INF) disArr[v] = -INF; // ������� ��ȯ�̶�� �������� ��ȯ
               else if (disArr[i] != INF && disArr[i] + weight + G[v] > disArr[v]) {
                   disArr[v] = disArr[i] + weight + G[v]; // ������Ʈ

                   if (k >= N) disArr[v] = -INF; // ��ȯã��
               }
           }
       }
   }

   if (disArr[D] == -INF) cout << "Gee"; // ��ȯ�� ����
   else if (disArr[D] == INF) cout << "gg"; // ���� �Ұ��� 
   else cout << disArr[D];

   return 0;

}