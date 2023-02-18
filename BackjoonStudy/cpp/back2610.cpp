#include <iostream>
#include <vector>
#include <map>

using namespace std;

// N : �����ϴ� ���
int N, K, f, b;

constexpr int INF = INT_MAX/2;

constexpr int MAX = 101;

vector<pair<int, int>> graph[MAX];

int disArr[MAX][MAX];

bool isVisted[MAX];

int check(int now, int repre, int value)
{
	for (int j = 1; j <= N; j++) {
		if (now == j) continue;
		if (value > disArr[now][j] && disArr[now][j] > 0)
		{
			repre = j;
			value = disArr[now][j];

		}
	} 

	return check(repre, repre, value);
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	// ���θ� �˰� ����(�����)
	for (int i = 0; i < K; i++) {
		cin >> f >> b;
		graph[f].push_back(make_pair(b, 1));
		graph[b].push_back(make_pair(f, 1));
	}

	// �ִ� �Ÿ� �迭 disArr �迭�� INF �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			disArr[i][j] = INF;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int v = graph[i][j].first;
			int weight = graph[i][j].second;
			disArr[i][v] = weight;
		}
	}


	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) disArr[i][j] = 0;
				else disArr[i][j] = min(disArr[i][j], disArr[i][k] + disArr[k][j]);
			}
		}
	}

	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << i << " -> " << j << " : " << disArr[i][j] << "   ";
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "\n";
	for (int i = 1; i <= N; i++) {
		int result = 0;
		int value = 1000;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (value > disArr[i][j] && disArr[i][j] > 0)
			{
				result = j;
				value = disArr[i][j];
			}
		}
	}

	for (int i = 1; i <= N ; i++)
	{
		
		if (isVisted[i] == false)
		{
			isVisted[i] = true;
			int result = check(i, i, INF);
			cout << "��� :  " << result << " \n";
		}



	}


	return 0;
}