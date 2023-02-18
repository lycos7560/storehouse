#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, tempO, tempT;

int cntCB[101];

bool isVisted[101];

queue<pair<int, int>> myQ;

vector<int> graph[101];

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	//cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	while (M--) {

		cin >> tempO >> tempT;
		// ��������� ��θ� �Է¹޴´�.
		graph[tempO].push_back(tempT);
		graph[tempT].push_back(tempO);
	}

	// 1�� ���� N������ ���� Ȯ��
	for (int i = 1; i <= N; i++) {
		// �湮 ó���� �ʱ�ȭ
		fill(isVisted, isVisted + 101, false);

		myQ.push(make_pair(i, 0));
		isVisted[i] = true;

		while (!myQ.empty()) {
			int now = myQ.front().first;
			int cnt = myQ.front().second;
			myQ.pop();

			for (int j = 0; j < graph[now].size(); j++) {
				
				if (isVisted[graph[now][j]] == true) continue;
				else {
					isVisted[graph[now][j]] = true;

					myQ.push(make_pair(graph[now][j], cnt + 1));
					cntCB[i] += cnt + 1;
				}
			}
		}
	}

	pair<int, int> resultP;
	resultP.second = INT32_MAX;
	for (int i = 1; i <= N; i++) {
		if (resultP.second > cntCB[i]) {
			resultP.second = cntCB[i];
			resultP.first = i;
		}
	}

	cout << resultP.first;

	return 0;
}