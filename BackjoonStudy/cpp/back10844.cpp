#include <iostream>

using namespace std;

constexpr int MOD = 1000000000;

int N;

// dp[i][j] 
// i = ����, j = �ڸ���
long long dp[10][101];

// DP �ʱ�ȭ
void DP_Initialization()
{
	dp[0][1] = 0;
	for (int i = 1; i < 10; i++) {
		dp[i][1] = 1;
	}
}

int main()
{
	cin >> N;

	long long result = 0;

	DP_Initialization();

	for (int j = 2; j <= N; j++) {
		for (int i = 0; i < 10; i++) {
			if (i == 0) { // ������ ���ڰ� 0
				dp[i][j] = dp[1][j-1]; 
			}
			else if (i == 9) { // ������ ���ڰ� 9
				dp[i][j] = dp[8][j-1];
			}
			else {
				// ��ⷯ ���� ����
				dp[i][j] = ( (dp[i-1][j-1] % MOD) + ( dp[i + 1][j - 1] % MOD) ) % MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		result += ( dp[i][N] % MOD ); // ��ⷯ ���� ����
	}

	cout << result % MOD; // ��ⷯ ���� ����

	return 0;
}