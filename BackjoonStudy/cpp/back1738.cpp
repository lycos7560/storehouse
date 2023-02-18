#include <iostream>
#include <vector>

using namespace std;

constexpr long long int INF = INT64_MAX;

constexpr int MAXN = 101;

vector<pair<int, int>> graph[MAXN];

long long int disArr[MAXN];

// N : ������ ����, M : ������ ����
int N, M, u, v, w;

int trace[MAXN];

int main()
{

	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;

	fill(disArr, disArr + MAXN, INF);

	disArr[1] = 0;

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		// �ܹ���
		graph[u].push_back(make_pair(v, -w));
	}


	// (��� ������ �� - 1) �� Ȯ���Ѵ�.
	// N ���� ��ȯ üũ
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {

				int u = i; // ������
				int v = graph[i][j].first; // ������
				int weight = graph[i][j].second; // ����ġ

				// ���� �ӽ� �迭�� ���Ѵ밡 �ƴϰ� &&
				// ���� �ӽ� �迭�� ����ġ�� �������� ����ġ���� ũ�ٸ�
				if (disArr[u] != INF && disArr[u] + weight < disArr[v]) {
					disArr[v] = disArr[u] + weight;
					trace[v] = u;

					// K == N �϶� ���� ������Ʈ �ȴٴ� �ǹ̴� 
					// ����Ŭ�� ���Եǰų� ����Ŭ���� ���� �������� ���� ����
					// ������ disArr[N] == -INF �ڵ带 ���Ͽ� ������ �ִ� ������� �Ǻ� 
					if (k == N) disArr[v] = -INF;
					// -INF�� ���̻� ������Ʈ�� ���´�.
				}
			}
		}
	}

	if (disArr[N] == INF || disArr[N] == -INF) cout << "-1";
	else {
		// ��θ� ������ �����Ѵ�.
		int now = N;
		vector<int> myV;
		while (now != 0) {
			myV.push_back(now);
			now = trace[now]; 
		}

		for (auto it = myV.rbegin(); it != myV.rend(); ++it) cout << *it << " ";

	}

	return 0;
}