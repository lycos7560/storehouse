#include <iostream>
#include <cmath>

using namespace std;

// X, Y ,W , H, 최솟값
int arr[5];

int main()
{
	arr[4] = INT32_MAX; // 최소값을 INT MAX 값으로 설정

	for (int i = 0; i < 4; i++) { cin >> arr[i]; }

	arr[4] = min(arr[4], abs(arr[0] - 0)); // |0 - X|
	arr[4] = min(arr[4], abs(arr[2] - arr[0])); // |W - X|
	arr[4] = min(arr[4], abs(arr[1] - 0)); // || |0 - Y|
	arr[4] = min(arr[4], abs(arr[3] - arr[1])); // |H - Y|

	cout << arr[4];

	return 0;
}