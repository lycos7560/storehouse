#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 10001;

// �������� ���� N, ��ӵ����� ���� D
int N, D;

int A, B, C;

/*
�� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� ����
a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
graph[a].push_back({b, c});
*/
vector<pair<int, int>> graph[MAXN];

// �ӽ� ���
int dist[MAXN];

int main()
{
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	// scanf�� ����ȭ�� ��Ȱ��ȭ
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		cin >> A >> B >> C;
		graph[A].push_back(make_pair(B, C));
	}

	// �⺻ �ʱ�ȭ
	for (int i = 0; i < MAXN; i++) dist[i] = i;

	int now = 0;
	while (true) {

		if (now == D) { 
			// �������� ���������Ƿ� ����� ���
			cout << dist[now];
			break;
		}

		// �ش� ��忡�� ����� ��� ��θ� Ȯ��
       for (int i = 0; i < graph[now].size(); i++) {

           // disSum = �ӽ� ��� + ���� ��忡�� i�ΰ��� ���
           int disSum = dist[now] + graph[now][i].second;
			
			// �������� �ؾ��� ���� continue
			if (disSum > D) continue; 


           // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
           if (disSum < dist[graph[now][i].first]) {
               // �ӽ� ��� ������Ʈ
				dist[graph[now][i].first] = disSum;

				// ���� ������Ʈ �ߴٸ� �� ������ �������� ���������� �÷��ش�.
				for (int j = graph[now][i].first + 1; j <= D ; j++) {
					// ����  dist[j]�� �� �۰ų� ���ٸ� �ִܰŸ��� �ִٴ� �ǹ� => Break
					if (disSum >= dist[j]) break;
					else dist[j] = ++disSum;
				}
           }
       }

		now++;
	}

	return 0;
}