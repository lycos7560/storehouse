#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int MAX = 101;

int T, N;

vector<pair<int, int>> graph[MAX];

bool isVisted[MAX], check;

pair<int, int> Start, Temp;

void DFSSearch(int x, int y)
{
	// ������ �����ϴٸ� ��ŷ�ϰ� ����
	if (x == graph[N][0].first && y == graph[N][0].second) {
		check = true;
	}

	for (int i = 0; i <= N; i++) {

		// �湮 �ߴٸ� �Ѿ��. 
		if (isVisted[i] == true) continue;
		// �Ÿ��� ���밪���� ������ �������� �Ұ������� üũ
		if (abs(graph[i][0].first - x) + abs(graph[i][0].second - y) <= 1000) {

			isVisted[i] = true; // �湮 üũ

			DFSSearch(graph[i][0].first, graph[i][0].second);
			// isVisted[i] = false; // �湮 üũ�� �����ϸ� �ð��ʰ�
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {

		// ���� �ʱ�ȭ
		fill(isVisted, isVisted + MAX, false);

		for (int i = 0; i < MAX; i++) graph[i].clear();

		check = false; // �������� �Ұ������� Ž��

		// ���� ��ġ�� �Է�
		cin >> N >> Start.first >> Start.second;	

		for (int i = 0; i <= N; i++) {

			// �������� ��ġ�� �Է¹޴´�.
			cin >> Temp.first >> Temp.second;
			// �������� ���� ��ġ�� �Է¹޴´�.
			graph[i].push_back(make_pair(Temp.first, Temp.second));

		}

		DFSSearch(Start.first, Start.second);
		
		if (check) cout << "happy\n";
		else cout << "sad\n";

	}

	return 0;
}