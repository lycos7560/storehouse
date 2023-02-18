#include <iostream>

using namespace std;

int value[10]; // 동전의 가치를 저장할 배열

int N, K, temp,  cnt = 0;

int main()
{
	cin >> N >> K;

	// 배열에 동전의 가치를 넣어 둔다.
	for (int i = 0; i < N; i++) cin >> value[i];

	// 가장 큰 동전부터 비교
	for (int i = N - 1; i >= 0; i--) {

		// K가 0이라면 목적 달성 break
		if (K == 0) break;
		
		temp = K / value[i];

		if (temp > 0) {
			cnt += temp;
			K -= temp * value[i];
		}
		else continue;
		// 동전의 가치가 남은 목표보다 크다면 continue;
	}

	// 결과를 출력한다.
	cout << cnt;

	return 0;
}