#include <iostream>
#include <vector>
#include <list>

using namespace std;

constexpr int INF = INT32_MAX / 2;

constexpr int MAX = 251;

vector<pair<int, int>> graph[MAX];

list<pair<int, int>> myList;

int disArr[MAX][MAX];

// N : ������ ��, M : ���� ��
int N, M, s, d, w, b, K, result;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// �ִ� �Ÿ� �迭 disArr �迭�� INF �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			disArr[i][j] = INF;
		}
	}

	// ���� ������ �Է�
	for (int i = 0; i < M; i++) {

		// ��� s, ���� d, b ��/�� ����
		cin >> s >> d >> b;

		if (b == 0) { // �ܹ���
			graph[s].push_back(make_pair(d, 0));
			disArr[d][s] = 1; // (disArr[i][k] + disArr[k][j] vs INF or 0)
		}
		else { // �����
			graph[s].push_back(make_pair(d, 0));
			graph[d].push_back(make_pair(s, 0));
		}

	}

	// ������ �Է� �޴´�.
	cin >> K;

	pair<int, int> tempP;

	while (K--) {
		cin >> tempP.first >> tempP.second;
		myList.push_back(tempP);
	}

	for (int i = 1; i <= N; i++) { // ���� ����
		for (int j = 0; j < graph[i].size(); j++) {

			int v = graph[i][j].first; // ������
			int weight = graph[i][j].second; // ����ġ
			if (disArr[i][v] > weight) disArr[i][v] = weight;
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

	for (auto it = myList.begin(); it != myList.end(); it++) {
		cout << disArr[it->first][it->second] << "\n";		
	}

	return 0;
}