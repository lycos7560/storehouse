#include <iostream>

using namespace std;

int N;
float arr[1001];

int main()
{
	cin >> N;

	float result = 0;
	int temp = 1;
	float Max = 0;

	while (temp <= N) {
		cin >> arr[temp];
		Max = max(Max, arr[temp]);
		temp++;
	}

	for (int i = 1; i <= N; i++) {
		arr[i] = (arr[i] / Max) * 100;
		result += arr[i];
	}

	cout << result / N;


	return 0;
}