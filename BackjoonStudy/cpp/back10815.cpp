#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAX = 500000;

int arr[MAX];

int N , M, target;

bool BinarySearch(int tArr[MAX], int start, int end, int target)
{
	if (start > end) return false; // �����ϴ� ����� ���� false turn

	int mid = (start + end) / 2; // �߰� ���� ã���ش�.

	if (arr[mid] == target)	return true; // �����ϴ� ���!! true return

	// ã�� ���� �� �۴ٸ�, �˻� ������ �� �۰��ؼ� �ٽ� �̺�Ž�� // ����� ������ return
	// ã�� ���� �� ũ��, �˻� ������ �� ũ���ؼ� �ٽ� �̺�Ž�� // ����� ������ return
	if (arr[mid] > target) return BinarySearch(arr, start, mid - 1, target);
	else return BinarySearch(arr, mid + 1, end, target);
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// �̺� Ž���� ���� ������ �����Ѵ�.
	sort(arr, arr + N);

	// Ž���� ������ ������ �Է¹޴´�.
	cin >> M;

	for (int i = 0; i < M; i++) {
		
		cin >> target;
		
		// ���� Ž�� �� ���
		cout << BinarySearch(arr, 0, N - 1, target) << "\n";

	}

	return 0;
}
