#include <iostream>

using namespace std;

constexpr int MAX = 100001;

int N, M;

int arr[MAX];

long long int dp[MAX];

pair<int, int> tempP;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[1];
	// �������� �������� ���� ���� ���´�.
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 0; i < M; i++) {

		cin >> tempP.first >> tempP.second;

		// ���� ��� 8 - 11�� ���� 
		// 1���� 11������ �տ��� 1���� 7������ ���� ���ָ� �ȴ�.
		cout << dp[tempP.second] - dp[tempP.first - 1] << "\n";

	}

	return 0;
}