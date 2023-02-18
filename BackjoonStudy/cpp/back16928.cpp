#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX = 101;

constexpr int INF = INT32_MAX;

// ��ٸ��� ���� �����Ѵ�.
vector<int> graph[MAX];

// BFS Ž���� ���� Queue
queue<pair<int,int>> myQueue;

// BFS Ž������ �ֻ����� ī��Ʈ,
// �湮ó�� �뵵�� ���
int map[MAX];

int N, M, tempO, tempT, result;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
   //cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// ���� ���� INF(INT32_MAX)�� �����Ѵ�.
	fill(map, map + MAX, INF);

	// ��ٸ��� ���� ��θ� �־��ش�.
	for (int i = 0; i < N + M; i++) {
		cin >> tempO >> tempT;
		// tempO -> tempT
		graph[tempO].push_back(tempT);
	}

	// 1������ ����, �ֻ��� Ƚ�� 0
	myQueue.push(make_pair(1,0));

	while (!myQueue.empty()) {

		int now = myQueue.front().first;
		int cnt = myQueue.front().second;
		myQueue.pop();

		// ����� �����ߴٸ� �Ѿ��.
		if (now == 100) {
			result = cnt;
			break;	
		} 

		for (int i = 1; i <= 6; i++) {

			int tempNow = now + i;

			// ���� 101�� ũ�ų� ���ٸ� �Ѿ��.
			// ����ġ 100�� ������������ ť�� �� �־ 
			// ����� ������ ����.
			if (tempNow >= MAX) continue;

			// �ش� ĭ�� �ִ� ��ٸ��� ���� Ȯ���ϰ� �����Ѵ�.
			for (int j = 0; j < graph[tempNow].size(); j++) {
				tempNow = graph[tempNow][j];
			}

			// �ش� ĭ�� �����Ҷ��� ī��Ʈ�� ������ ī��Ʈ���� ũ�ٸ�
			// �Ѿ��.
			if (map[tempNow] <= cnt + 1) continue;

			map[tempNow] = cnt + 1;
			myQueue.push(make_pair(tempNow, map[tempNow]));
		}
	}

	cout << result;

	return 0;
}