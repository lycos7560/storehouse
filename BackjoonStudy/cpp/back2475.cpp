#include <iostream>

using namespace std;

int arr[6];

int main()
{
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		arr[5] += arr[i] * arr[i];
	}

	cout << arr[5] % 10;

	return 0;
}