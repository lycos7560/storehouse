#include <iostream>

using namespace std;

int arr[101][2];
int N, temp;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		if (temp >= 0) arr[temp][0]++;
		else arr[temp * -1][1]++;
	}

	cin >> temp;
	if (temp >= 0) cout << arr[temp][0];
	else cout << arr[temp * -1][1];

	return 0;
}