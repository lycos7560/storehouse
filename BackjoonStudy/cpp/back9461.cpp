#include <iostream>

using namespace std;

int T, N;

// int형 범위를 넘어갈 수 있다.
long long int arr[101] = {0, 1, 1, 1, 2, 2};

int main()
{
	cin >> T;

	// 테스트 케이스 만큼 반복
	for (int i = 0; i < T; i++) {

		cin >> N;

		for (int j = 6; j <= N; j++) { 
			
			// 값이 있다면 연산할 필요가 없다.
			if (arr[j] == 0) arr[j] = arr[j - 1] + arr[j - 5];

		}

		// 결과 출력
		cout << arr[N] << "\n";
	}

	return 0;
}