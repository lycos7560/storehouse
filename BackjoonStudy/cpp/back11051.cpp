#include <iostream>

using namespace std;

constexpr int MAX = 1001;
constexpr int MOD = 10007;

// arr[i][j] 
// i �� ������ ����
// j ��å �� ����
// i ���� j���� �̾����� ���� ��� ��
int DP[MAX][MAX];

// DP �迭�� �ʱ�ȭ ���ִ� �Լ�
void DP_Initialiaztion()
{
	for (int i = 1; i < MAX; i++) {
		DP[i][1] = i; // i�� �� 1���� �̴� ����� ���� i��
		DP[i][0] = 1; // i�� �� 1���� �������� �ʴ� ����� ���� 1��
		DP[i][i] = 1; // i�� �� i���� �����ϴ� ����� ���� 1��
	}
}

int main()
{
	int N, K;
	cin >> N >> K;

	// �迭 �ʱ�ȭ
	DP_Initialiaztion();

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			// ��ⷯ ���
			DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1]) % MOD;
		}
	}

	cout << DP[N][K]; // ��� ����ϱ�

	return 0;
}