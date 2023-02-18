#include <iostream>
#include <vector>

using namespace std;

constexpr long long int INF = INT64_MAX;

constexpr int MAXN = 501;

long long int disArr[MAXN];

// N : ������ ����, M : ���� �뼱�� ����
// A : ���� ����, B : ���� ����, C : �ɸ��� �ð�
int N, M, A, B, C;

vector<pair<int, int>> graph[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		// �ܹ���
		graph[A].push_back(make_pair(B, C));
	}

	// �迭 �ʱ�ȭ
	fill(disArr, disArr + MAXN, INF);

	disArr[1] = 0;

	for (int k = 1; k <= N; k++) {// (��� ������ �� - 1) �� Ȯ���Ѵ�.

		// ��� �뼱�� Ȯ���Ѵ�.
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {

				int u = i; // ������
				int v = graph[i][j].first; // ������
				int weight = graph[i][j].second; // ����ġ

				// ���� �ӽ� �迭�� ���Ѵ밡 �ƴϰ� &&
				// ���� �ӽ� �迭�� ����ġ�� �������� ����ġ���� �۴ٸ�
				if (disArr[u] != INF && disArr[u] + weight < disArr[v]) {

					disArr[v] = disArr[u] + weight; // �ӽù迭�� ������Ʈ ���ش�.

					// K�� N-1�϶� ��� ������ Ȯ���� ��
					// K�� N�϶� ������Ʈ�� �ִٸ� ���� ��ȯ�� �ִٴ� �̾߱�
					if (k == N) { 
						cout << "-1";
						return 0;
					}
				}
			}
		}

		cout << " \n";
		for (int i = 2; i <= N; i++) {

			cout << i << " : " << disArr[i] << "\n";

			//if (disArr[i] == INF) cout << "-1" << "\n";
			//else cout << disArr[i] << "\n";
		}
	}



	return 0;
}