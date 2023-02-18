#include <iostream>

using namespace std;

long long int arr[1001];

constexpr int MOD = 10007;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	 // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> arr[0];

	// DP �迭�ʱ�ȭ
	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= arr[0]; i++) 	
		arr[i] = (arr[i - 1] % MOD + (arr[i - 2] * 2) % MOD) % MOD;

	cout << arr[arr[0]];

	return 0;
}