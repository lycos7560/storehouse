#include <iostream>

using namespace std;

int N;

int dp[13];

int main()
{
	cin >> N;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (dp[i] == 0) dp[i] = dp[i - 1] * i;
	}

	cout << dp[N];

	return 0;
}