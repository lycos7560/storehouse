#include <iostream>

using namespace std;

int N, temp, result;

int arr[101];

int main()
{
	cin >> N;
	// N��ŭ �Է��� �޴´�.
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		temp = 0;
		for (int j = 1; j <= arr[i]; j++) {
			// �ڽ��� 1 ~ �ڽű��� ���� ������ ����.
			// ���� �������� 0�� �Ǵ� ��찡 2��� �Ҽ�
			if (arr[i] % j == 0) { 
				temp++; 
			} 
		}

		// ����� 2��� 1�� �ڽŸ� �ִٴ� ������ �Ҽ�
		if (temp == 2 ) { result++; }
	}

	cout << result; // ��� ���
	return 0;
}