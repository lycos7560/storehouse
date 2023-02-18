#include <iostream>

using namespace std;

// �����Ϸ��� ī���� ����
int N, result;

int arr[1001];

// dp[i][j] = �ִ밪
// i = ��ǥ�� ī���
// j = ī���� ����
int dp[1001][1001];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}


	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			if (i > j) {
				dp[j][i] = dp[j][i - 1];
			}
			else
			{
				dp[j][i] = max(dp[j][i - 1], dp[j - i][i] + arr[i]);
			}
		}
	}

	cout << dp[N][N];

	return 0;
}