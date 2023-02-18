#include <iostream>
#include <cmath>

using namespace std;

int M, N, temp;

int arr[10000001];

int main()
{
	cin >> M >> N;

	temp = sqrt(N);
	arr[0] = 0;
	arr[1] = 0;

	// �迭 �ʱ�ȭ
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= temp; i++) {

		// ���� 0 �̶�� ���� '������ ��' ��� �ǹ�
		if (arr[i] == 0) continue;

		// �̹� ������ ���ڰ� �ƴ϶��, 
		// �� ������� ����Ͽ�, ������ ��� ���� �����
		for (int j = 2 * i; j <= N; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = M; i <= N; i++) {

		if (arr[i] == 0) continue;
		else cout << arr[i] << "\n";
	}

	return 0;
}