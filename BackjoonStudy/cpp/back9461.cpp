#include <iostream>

using namespace std;

int T, N;

// int�� ������ �Ѿ �� �ִ�.
long long int arr[101] = {0, 1, 1, 1, 2, 2};

int main()
{
	cin >> T;

	// �׽�Ʈ ���̽� ��ŭ �ݺ�
	for (int i = 0; i < T; i++) {

		cin >> N;

		for (int j = 6; j <= N; j++) { 
			
			// ���� �ִٸ� ������ �ʿ䰡 ����.
			if (arr[j] == 0) arr[j] = arr[j - 1] + arr[j - 5];

		}

		// ��� ���
		cout << arr[N] << "\n";
	}

	return 0;
}