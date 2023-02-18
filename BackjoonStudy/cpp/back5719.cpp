#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int INF = INT32_MAX;

int disArr[501];

priority_queue<pair<int, int>> mypq;

vector<pair<int, int>> graph[10001];

vector<int> trace[501];

int N, M, S, D, U, V, P;

void MyDijstra()
{  
   for (int i = 0; i <= N; i++) disArr[i] = INF;

   for (int i = 0; i < M; i++) {
       cin >> U >> V >> P;
       graph[U].push_back(make_pair(V, P));
   }

   // �켱���� ť�� ����.
   mypq.push({ 0, S }); // < first : �Ÿ� , second : ��� �ε��� >

   disArr[S] = 0;

   while (!mypq.empty()) {
       // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
       // (�ּ������� ����)
       int ncost = -mypq.top().first;
       int now = mypq.top().second;

       mypq.pop();

       // �̹� ��� �ִ� �ͺ��� �Ÿ��� ũ�� �Ѿ��.
       if (disArr[now] < ncost) continue;

       // �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {
           // dissum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           int dissum = ncost + graph[now][i].second;
           // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           // ���Ƶ� Ȯ���� �ʿ��ϴ�.
           // �ּ� �Ÿ��� ������ ���� �� �ֱ� ����
           if (dissum <= disArr[graph[now][i].first]) {

               if (dissum < disArr[graph[now][i].first]) {
               
                   // �ӽ� ��� ������Ʈ
                   disArr[graph[now][i].first] = dissum;

                   trace[graph[now][i].first].clear(); // ���� �����Ѵٸ� ���� �ִ� ���� �ʿ䰡 ����.
                   trace[graph[now][i].first].push_back(now); // ��θ� ����

                   // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
                   mypq.push(make_pair(-dissum, graph[now][i].first));
               }
               else trace[graph[now][i].first].push_back(now); // ��θ� ����   
           }
       }
   }

   // �ִ� �Ÿ��� ��θ� ������ �ݴϴ�.
   queue<int> delQ;
   delQ.push(D);
   while (!delQ.empty()) {
       int nowDel = delQ.front();
       delQ.pop();
       for (int i = 0; i < trace[nowDel].size(); i++) {
           for (auto it = graph[trace[nowDel][i]].begin(); it != graph[trace[nowDel][i]].end(); it++) {
               if ((*it).first == nowDel) {
                   delQ.push(trace[nowDel][i]);
                   graph[trace[nowDel][i]].erase(it);
                   break;
               }
           }
       }
   }


   // ���ο� ����ũ��Ʈ�� �����Ͽ� ���� �ִ� ��θ� ã�´�.
   for (int i = 0; i <= N; i++) disArr[i] = INF;
   // �켱���� ť�� ����.
   mypq.push({ 0, S }); // first : �Ÿ� , second : ��� �ε���
   disArr[S] = 0;
   while (!mypq.empty()) {
       // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
       // (�ּ������� ����)
       int ncost = -mypq.top().first;
       int now = mypq.top().second;

       mypq.pop();

       // �̹� ��� �ִ� �ͺ��� �Ÿ��� ũ�� �Ѿ��.
       if (disArr[now] < ncost) continue;

       // �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {
           // dissum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           int dissum = ncost + graph[now][i].second;
           // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           if (dissum < disArr[graph[now][i].first]) {

               disArr[graph[now][i].first] = dissum;
               // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
               mypq.push(make_pair(-dissum, graph[now][i].first));
           }
       }
   }

   for (int i = 0; i <= N; i++) trace[i].clear();
   for (int i = 0; i <= M; i++) graph[i].clear();
}


int main()
{
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   //cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(NULL);
   std::cout.tie(NULL);

   while (true) {

       cin >> N >> M;

       if (N == 0 && M == 0) break;

       cin >> S >> D;

       MyDijstra();

       if (disArr[D] == INF) cout << -1 << "\n";
       else cout << disArr[D] << "\n";
   }

   return 0;
}