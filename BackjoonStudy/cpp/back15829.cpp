#include <iostream>
#include <cmath>

constexpr int MOD = 1234567891;

using namespace std;

int N;

long long int result, temp;

string str;

long long int dp[51];

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);
	result = 0;
	dp[0] = 1;

	cin >> N >> str;

	for (int i = 1; i <= N; i++) {
		dp[i] = (dp[i - 1] * 31) % MOD;
	}

	for (int i = 0; i < str.length(); i++) {
		N = str[i] - 'a' + 1;
		temp = dp[i];
		temp *= N;
		temp %= MOD;
		result += temp;
		result %= MOD;
	}


	cout << result;
	return 0;
}