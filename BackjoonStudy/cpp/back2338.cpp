#include <iostream>

using namespace std;

int N;

int dp[50001];

int main()
{
	cin >> N;

	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		int minN = INT32_MAX;
		for (int j = 1; j * j <= i; j++) {
			int tmp = i - j * j;
			minN = min(minN, dp[tmp]);
		}
		dp[i] = minN + 1;
	}

	cout << dp[N];

	return 0;
}