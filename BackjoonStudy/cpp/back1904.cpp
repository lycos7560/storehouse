#include <iostream>

using namespace std;

long long int dp[1000001];

constexpr int MOD = 15746;

int main()
{
	cin >> dp[0];

	// DP �迭 �ʱ�ȭ
	for (int i = 1; i < 3; i++) 
		dp[i] = i;

	for (int i = 3; i <= dp[0]; i++) 	// ��ⷯ ���
		dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD ) % MOD;

	cout << dp[dp[0]];

	return 0;
}