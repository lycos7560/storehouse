#include <iostream>

using namespace std;

int dp[1001][10];

int N, result;

constexpr int MOD = 10007;

int main()
{
	cin >> N;

	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= 9; j++)
			dp[i][j] = i;

	for (int i = 1; i <= N; i++) dp[i][9] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 8; j >= 0; j--)
			dp[i][j] = ( dp[i][j+1] % MOD + dp[i-1][j] % MOD ) % MOD;

	result = 0;
	for (int i = 0; i <= 9; i++) {
		result += dp[N][i];
		result %= MOD;
	}

	cout << result;

	return 0;
}