#include <iostream>
#include <cmath>

using namespace std;

int M, N, temp;

int arr[10000001];

int main()
{
	cin >> M >> N;

	temp = sqrt(N);
	arr[0] = 0;
	arr[1] = 0;

	// 배열 초기화
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= temp; i++) {

		// 값이 0 이라는 뜻은 '지워진 수' 라는 의미
		if (arr[i] == 0) continue;

		// 이미 지워진 숫자가 아니라면, 
		// 그 배수부터 출발하여, 가능한 모든 숫자 지우기
		for (int j = 2 * i; j <= N; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = M; i <= N; i++) {

		if (arr[i] == 0) continue;
		else cout << arr[i] << "\n";
	}

	return 0;
}