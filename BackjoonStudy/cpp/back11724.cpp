#include <iostream>

using namespace std;

int N, M, cnt = 0;

pair<int, int> tempPair;

bool arr[1001][1001];

void CheckNode(int A)
{
	arr[A][0] = false; // �湮ó��
	for (int i = 1; i <= N; i++) {
		if (A == i) continue;

		// ����� Ž��
		if ((arr[i][0] == true && arr[i][A] == true) || (arr[i][0] == true && arr[A][i] == true)) 
			CheckNode(i);
	}
}


int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// �ڱ� �ڽ��� �׻� �ڱ� �ڽ��� ���� ��ҿ� ���Ѵ�.
	for (int i = 1; i <= N; i++) arr[i][0] = true;


	for (int i = 0; i < M; i++) {
		cin >> tempPair.first >> tempPair.second;
		arr[tempPair.first][tempPair.second] = true;
		arr[tempPair.first][0] = true;
		arr[tempPair.second][0] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (arr[i][0] == false) continue; // �湮ó���� �Ǿ��ִٸ� �Ѿ��.
		else 
		{
			CheckNode(i);
			cnt++; // ������ ī��Ʈ + 1
		}
	}

	cout << cnt;

	return 0;
}