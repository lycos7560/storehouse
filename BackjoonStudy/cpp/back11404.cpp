#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = INT32_MAX/2;

constexpr int MAX = 101;

vector<pair<int, int>> graph[MAX];

int disArr[MAX][MAX];

// N : ������ ��, M : ������ ��
int N, M, s, d, w;

int main()
{	
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// �뼱�� �Է�
	for (int i = 0; i < M; i++) {

		// �ܹ��� ������� ��� s, ���� d, ��� w
		cin >> s >> d >> w;

		graph[s].push_back(make_pair(d, w));
	}

	// �ִ� �Ÿ� �迭 disArr �迭�� INF �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (i == j) disArr[i][j] = 0;
			else disArr[i][j] = INF;

		}
	}

	for (int i = 1; i <= N; i++) { // ���� ����
		for (int j = 0; j < graph[i].size(); j++) {

			int v = graph[i][j].first; // ������
			int weight = graph[i][j].second; // ����ġ

			if (disArr[i][v] > weight) 	disArr[i][v] = weight;

		}
	}
	
	// ������ �÷��̵�
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (i == j) disArr[i][j] = 0;
				else disArr[i][j] = min(disArr[i][j], disArr[i][k] + disArr[k][j]);

			}
		}
	}

	// ��� ���
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (disArr[i][j] == INF) cout << 0 << " ";
			else cout << disArr[i][j] << " ";

		}

		cout << "\n";

	}

	return 0;
}