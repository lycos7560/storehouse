#include <iostream>

using namespace std;

int arr[10];

int main()
{
	int temp = 1, Max = INT32_MIN;

	// 9���� ���ڸ� �Է� ����
	while (temp <= 9) {
		cin >> arr[temp];
		temp++;
	}

	temp = 0;
	for (int i = 1; i <= 9; i++) {
		if (Max < arr[i]) {
			// arr[i] i��°�� �ִ밪�̶�� 
			// �ε��� ���� �����ϰ� �ִ밪�� ����
			Max = arr[i];
			temp = i;
		}
	}

	// �ִ밪, �ε��� ���
	cout << Max << "\n" << temp;

	return 0;
}