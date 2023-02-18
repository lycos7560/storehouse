#include <iostream>
#include <algorithm>

using namespace std;

int N, result;

int arr[1000], dp[1000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N); // ������������ ����

	// dp �� ��� �ʱⰪ ����
	dp[0] = arr[0];
	result += arr[0];

	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1] + arr[i];
		result += dp[i];
	}

	cout << result;

	return 0;
}