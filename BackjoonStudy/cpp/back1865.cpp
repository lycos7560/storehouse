#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 501;

int disArr[MAXN];

int TC, N, M, W, S, E, T;

vector<pair<int, int>> graph[MAXN];

bool BellmanFord()
{
	cin >> N >> M >> W;

	vector<pair<int, int>> graph[MAXN];

	// ������ ������ �Է¹޴´�.
	for (int i = 0; i < M; i++) {
		cin >> S >> E >> T;
		// �����
		graph[S].push_back(make_pair(E, T));
		graph[E].push_back(make_pair(S, T));
	}

	// ��Ȧ�� ������ �Է¹޴´�.
	for (int i = 0; i < W; i++) {
		cin >> S >> E >> T;
		// �ܹ���
		graph[S].push_back(make_pair(E, -T));
	}

	// ����� ��𿡻� �ص� ����� ����.
	fill(disArr, disArr + MAXN, 0);

	// (��� ������ �� - 1) �� Ȯ���Ѵ�.
	// N ���� ��ȯ üũ
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) { // ���� ����
			for (int j = 0; j < graph[i].size(); j++) {
				int v = graph[i][j].first; // ������
				int weight = graph[i][j].second; // ����ġ
	
				// ���� �ӽ� �迭�� ����ġ�� �������� ����ġ���� ũ�ٸ�
				if (disArr[i] + weight < disArr[v]) {
					disArr[v] = disArr[i] + weight;

					// K == N �϶� ���� ������Ʈ �ȴٴ� �ǹ�
					if (k == N) return true; // ��ȯ�� ����
					
				}
			}
		}
	}

	return false;
	// ��ȯ�� ����
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> TC;

	for (int i = 0; i < TC; i++) {

		if (BellmanFord()) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}