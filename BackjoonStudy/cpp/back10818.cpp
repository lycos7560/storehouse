#include <iostream>

using namespace std;

int arr[10];

int main()
{
	int temp = 1, Max = INT32_MIN;

	// 9개의 숫자를 입력 받음
	while (temp <= 9) {
		cin >> arr[temp];
		temp++;
	}

	temp = 0;
	for (int i = 1; i <= 9; i++) {
		if (Max < arr[i]) {
			// arr[i] i번째가 최대값이라면 
			// 인덱스 값을 저장하고 최대값을 변경
			Max = arr[i];
			temp = i;
		}
	}

	// 최대값, 인덱스 출력
	cout << Max << "\n" << temp;

	return 0;
}