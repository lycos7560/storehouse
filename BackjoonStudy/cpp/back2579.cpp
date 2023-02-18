#include <iostream>

using namespace std;

// N : 계단의 개수
int N;

// value[N] = N번째 계단의 가치
int value[301];

// dp[N] = N번째 계단의 최고 가치
int arr[301];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> value[i];

	// dp 값 초기화
	arr[0] = 0;
	arr[1] = value[1];
	arr[2] = value[2] + value[1];

	for (int j = 3; j <= N; j++) {
		arr[j] = max(arr[j - 2] + value[j], arr[j - 3] + value[j] + value[j - 1]);
	}

	cout << arr[N];

	return 0;
}