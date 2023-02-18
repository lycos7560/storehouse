#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

constexpr int MAXN = 125;
constexpr int INF = INT32_MAX;

// Ž���ϴ� ���� ���� =>  ��, �� ,�� ,��
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int N, nowX, nowY, dcost;

int map[MAXN][MAXN], dis[MAXN][MAXN];

tuple<int, int, int> nowTuple;

// ����ġ, x,y ��ǥ
priority_queue<tuple<int, int, int>> myPQ;

queue<int> resQ;


int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> N; // �׽�Ʈ ���̽��� 0�̸� break;
		if (N == 0) break;

		// 2���� �迭 �ʱ�ȭ
		// ��ü �ʱ�ȭ : ó������ [0][0]�� ���ְ�, 
		// �� ���� ĭ���� [�ִ� ��(��) - 1][�ִ� ��], ���� ĭ���� �ʱ� ������ ��
		// �������� �ӽ� ��带 ���Ѵ� ����
		fill(&dis[0][0], &dis[N - 1][N], INF);

		// �׽�Ʈ ���̽��� �Է��� �޴´�.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		// �켱���� ť�� �̿��ϱ� ���Ͽ� ������ �ִ� ���� �������
		myPQ.push(make_tuple(-map[0][0], 0, 0));

		while (!myPQ.empty()){

			// 0�� �ε��� ����ġ, 1�� �ε��� X��ǥ, 2�� �ε��� Y��ǥ
			nowTuple = myPQ.top();
			myPQ.pop();

			if (get<1>(nowTuple) == N - 1 && get<1>(nowTuple) == N - 2) break;

			// ��/��/��/�츦 Ž���ϱ� ���� �ݺ���
			for (int i = 0; i < 4; i++) {
				nowX = get<1>(nowTuple) + dxdy[i][0];
				nowY = get<2>(nowTuple) + dxdy[i][1];
				dcost = get<0>(nowTuple) * -1;

				// ������ ������ ����� ��� => �Ѿ��.
				if (nowX < 0 || nowY < 0 || nowX >= N || nowY >= N) continue;
				// ���� ��ġ�� �ּ� ���Ϸ��� + ���� ĭ�� ���Ϸ����� ũ�� >= Ž�� ��ġ�� �ּ� ���Ϸ���
				if (dcost + map[nowX][nowY] >= dis[nowX][nowY]) continue;
				else {
					// �ӽ� ��� ������Ʈ
					dis[nowX][nowY] = dcost + map[nowX][nowY];
					myPQ.push(make_tuple( -dis[nowX][nowY], nowX, nowY));
				}
			}
		}

		resQ.push(dis[N - 1][N - 1]);
	}

	int cnt = 1;
	while (!resQ.empty()){
		cout << "Problem " << cnt << ": " << resQ.front() << "\n";
		resQ.pop();
		cnt++;
	}

	return 0;
}


