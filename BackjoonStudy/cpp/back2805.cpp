#include <iostream>

using namespace std;

// ������ �� : N , ������ ���������� �ϴ� ������ ���� : M
long long int N, M, maxN, result, temp = INT64_MAX;
long long int arr[1000001];

// ����Ž���� �����ϴ� �Լ�
void BinarySearch(long long int start, long long int end)
{
	if (start >= end) return;

	long long int mid = ((start + end) / 2);

	temp = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] <= mid) continue; // ����� ���̰� �������� �� ���
		temp += (arr[i] - mid);
	}
		
	if (temp >= M) {
		result = max(mid, result);
		BinarySearch(mid + 1, end);
	}
	else {
		BinarySearch(start, mid);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (maxN < arr[i]) maxN = arr[i]; // �ְ� ���� ã�´�.
	}

	// 1 - Top Ž�� ����
	BinarySearch(1, maxN + 1);

	cout << result;

	return 0;
}