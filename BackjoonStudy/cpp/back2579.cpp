#include <iostream>

using namespace std;

// N : ����� ����
int N;

// value[N] = N��° ����� ��ġ
int value[301];

// dp[N] = N��° ����� �ְ� ��ġ
int arr[301];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> value[i];

	// dp �� �ʱ�ȭ
	arr[0] = 0;
	arr[1] = value[1];
	arr[2] = value[2] + value[1];

	for (int j = 3; j <= N; j++) {
		arr[j] = max(arr[j - 2] + value[j], arr[j - 3] + value[j] + value[j - 1]);
	}

	cout << arr[N];

	return 0;
}