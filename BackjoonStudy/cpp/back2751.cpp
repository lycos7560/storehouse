#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000000];

int N, temp;

int main()
{
	ios_base::sync_with_stdio(false); // 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}