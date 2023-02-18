#include <iostream>

using namespace std;

int N, M;

int arr[100];

int temp, sum = INT32_MIN;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int  i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) { continue; }
			for (int k = 0; k < N; k++) {
				if (i == j || j == k || i == k) { continue; }
				temp = 0;
				temp = arr[i] + arr[j] + arr[k];
				if (sum < temp && M >= temp) {
					sum = temp;
				}
			}
		}
	}

	cout << sum;

	return 0;
}