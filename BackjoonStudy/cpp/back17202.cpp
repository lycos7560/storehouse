#include <iostream>
#include <string>

using namespace std;

int arr[16];

// 입력을 받는 함수
void GetInput()
{
	string tempA, tempB;
	cin >> tempA >> tempB;

	int temp = 0;
	for (int i = 0; i < 8; i++){ // arr 배열에 셋팅
		arr[temp++] = tempA[i] - '0'; // char => int
		arr[temp++] = tempB[i] - '0'; // char => int
	}
}

int main()
{
	GetInput();
	
	// 14번 연산
	for (int i = 15; i > 1; i--) {
		for (int j = 0; j < i; j++) {
			arr[j] = (arr[j] + arr[j + 1]) % 10;
		}
	}

	cout << arr[0] << arr[1];

	return 0;
}