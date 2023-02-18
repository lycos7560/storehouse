#include <iostream>

using namespace std;

int N, temp, result;

int arr[101];

int main()
{
	cin >> N;
	// N만큼 입력을 받는다.
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		temp = 0;
		for (int j = 1; j <= arr[i]; j++) {
			// 자신을 1 ~ 자신까지 전부 나누어 본다.
			// 만약 나머지가 0이 되는 경우가 2라면 소수
			if (arr[i] % j == 0) { 
				temp++; 
			} 
		}

		// 결과가 2라면 1과 자신만 있다는 뜻으로 소수
		if (temp == 2 ) { result++; }
	}

	cout << result; // 결과 출력
	return 0;
}