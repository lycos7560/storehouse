#include <iostream>
#include <algorithm>

using namespace std;

long long int arr[10001];

long long int K, N, top,temp, result;

// ����Ž���� �����ϴ� �Լ�
void BinarySearch(long long int start, long long int end)
{
	if (start >= end) return;

	long long int mid = ((start + end) / 2);

	temp = 0;
	for (int i = 1; i <= K; i++) temp += (arr[i] / mid);
	
	if (temp < N) {
		BinarySearch(start, mid);
	}
	else {
		result = max(mid, result);
		BinarySearch(mid + 1, end);
	}

}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;

	for (int i = 1; i <= K; i++) {
		cin >> arr[i];
		if (top < arr[i]) top = arr[i]; // ���� ū ���� ã�´�.
	}

	// �̺� Ž�� ����
	BinarySearch(1, top + 1);

	cout << result;

	return 0;
}