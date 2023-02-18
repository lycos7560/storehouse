#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <tuple>
#include <map>

using namespace std;

constexpr int inf = int32_max;

int disarr[502];

bool check[502][502];

int n, m, s, d, u, v, p;

int dijstra()
{
   int result = inf;

   memset(disarr, inf, sizeof disarr);

   memset(check, false, sizeof check);

   priority_queue<tuple<int, int, list<pair<int, int>>>> firstpq;

   vector<pair<int, int>> graph[10001];

   list<pair<int, int>> mylist;

   multimap<int, list<pair<int, int>>> mymap;

   for (int i = 0; i < m; i++) {
       cin >> u >> v >> p;
       graph[u].push_back(make_pair(v, p));
   }

   // �켱���� ť�� ����.
   firstpq.push({ 0, s, mylist }); // < first : �Ÿ� , second : ��� �ε��� >
   disarr[s] = 0;
   while (!firstpq.empty()) {
       // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
       // (�ּ������� ����)
       int ncost = -get<0>(firstpq.top());
       int now = get<1>(firstpq.top());
       mylist = get<2>(firstpq.top());
       firstpq.pop();

       // �̹� ��� �ִ� �ͺ��� �Ÿ��� ũ�� �Ѿ��.
       if (disarr[now] < ncost) continue;

       // �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {
           list<pair<int, int>> templist = mylist;
           // dissum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           int dissum = ncost + graph[now][i].second;

           // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           if (dissum <= disarr[graph[now][i].first]) {

               templist.push_back(make_pair(now, graph[now][i].first));


               if (dissum < disarr[graph[now][i].first])
               {
                   // �ӽ� ��� ������Ʈ
                   disarr[graph[now][i].first] = dissum;
                   // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
                   firstpq.push(make_tuple(-dissum, graph[now][i].first, templist));

               }

               if (graph[now][i].first == d && result >= dissum) {
                   result = dissum;
                   mymap.insert(make_pair(dissum, templist));
               }

           }
       }
   }

   result = disarr[d];

   for (auto mit = mymap.begin(); mit != mymap.end(); mit++) {
       if (result == mit->first) {
           for (auto it = mit->second.begin(); it != mit->second.end(); it++) {
               check[it->first][it->second] = true;
           }
       }

       else break;
   }

   priority_queue<pair<int, int>> mypq;

   memset(disarr, inf, sizeof disarr);

   // �켱���� ť�� ����.
   mypq.push({ 0, s }); // < first : �Ÿ� , second : ��� �ε��� >
   disarr[s] = 0;

   while (!mypq.empty()) {
       // -�� ���̴� ������ �켱���� ť�� �̿��Ͽ� �����ϱ� �����̴�.
       // (�ּ������� ����)
       int ncost = -mypq.top().first;
       int now = mypq.top().second;
       mypq.pop();

       // �̹� ��� �ִ� �ͺ��� �Ÿ��� ũ�� �Ѿ��.
       if (disarr[now] < ncost) continue;
       // �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {
           if (check[now][graph[now][i].first] == true) continue;
           // dissum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           int dissum = ncost + graph[now][i].second;
           // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           if (dissum < disarr[graph[now][i].first]) {
               // �ӽ� ��� ������Ʈ
               disarr[graph[now][i].first] = dissum;
               // �켱���� ť�� (�Ÿ�, ��� �ε���) Ǫ��
               mypq.push(make_pair(-dissum, graph[now][i].first));
           }
       }
   }

   return disarr[d];
}


int main()
{
   ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   //cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
   cin.tie(null);
   std::cout.tie(null);

   while (true) {

       cin >> n >> m;

       if (n == 0 && m == 0) break;

       cin >> s >> d;

       int result = dijstra();

       if (result == inf) cout << -1 << "\n";
       else cout << result << "\n";
   }



   return 0;
}