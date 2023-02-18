#include <iostream>

using namespace std;

constexpr int MAX = 21;

int disArr[MAX][MAX];

int route[MAX][MAX];

int N, result;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> disArr[i][j];
			route[i][j] = disArr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {

				if (j == k || i == k) continue;

				// �Ұ����� ����̹Ƿ� -1 ���
				if (disArr[i][j] > disArr[i][k] + disArr[k][j]) {
					cout << "-1";
					return 0;
				}

				// ��θ� �����ش�.
				if (disArr[i][j] == disArr[i][k] + disArr[k][j]) route[i][j] = 0;
			}
		}
	}


	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) result += route[i][j];
	
	// ������ �������ش�.
	cout << result/2;

	return 0;
}