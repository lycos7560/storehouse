#include <iostream>

using namespace std;

int N, temp;
int arr[2];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		temp = i;
		while (temp % 2 == 0) {
			arr[0]++;
			temp = temp / 2;
		}

		while (temp % 5 == 0) {
			arr[1]++;
			temp = temp / 5;
		}
	}

	cout << min(arr[0], arr[1]);

	return 0;
}