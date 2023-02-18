#include <iostream>

using namespace std;

int arr[1000001];

int main()
{
	cin >> arr[0];
	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i <= arr[0]; i++) {
		arr[1] = arr[i - 1] + 1;

		if (i % 2 == 0) arr[1] = min(arr[1], arr[i / 2] + 1);

		if (i % 3 == 0) arr[1] = min(arr[1], arr[i / 3] + 1);

		arr[i] = arr[1];
	}

	cout << arr[arr[0]];
	return 0;
}