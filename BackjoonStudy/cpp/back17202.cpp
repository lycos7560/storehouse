#include <iostream>
#include <string>

using namespace std;

int arr[16];

// �Է��� �޴� �Լ�
void GetInput()
{
	string tempA, tempB;
	cin >> tempA >> tempB;

	int temp = 0;
	for (int i = 0; i < 8; i++){ // arr �迭�� ����
		arr[temp++] = tempA[i] - '0'; // char => int
		arr[temp++] = tempB[i] - '0'; // char => int
	}
}

int main()
{
	GetInput();
	
	// 14�� ����
	for (int i = 15; i > 1; i--) {
		for (int j = 0; j < i; j++) {
			arr[j] = (arr[j] + arr[j + 1]) % 10;
		}
	}

	cout << arr[0] << arr[1];

	return 0;
}