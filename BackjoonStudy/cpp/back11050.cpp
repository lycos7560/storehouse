//#include <iostream>
//
//using namespace std;
//
//int N, K;
//
//// 팩토리얼을 계산하는 함수
//int factorial(int number)
//{	
//	int result = 1;
//	for (int i = 1; i <= number; i++) {
//		result = result * i;
//	}
//
//	return result;
//}
//
//int main()
//{
//	cin >> N >> K;
//	cout << factorial(N) / (factorial(K) * factorial(N - K));
//	return 0;
//} 

#include <iostream>

using namespace std;

// arr[i][j] 
// i 총 숫자의 개수
// j 선책 수 개수
// i 개중 j개를 뽑았을때 조합 경우 수
int arr[11][11];

// DP 배열을 초기화 해주는 함수
void DP_Initialiaztion()
{
	for (int i = 1; i < 11; i++) {
		arr[i][1] = i; // i개 중 1개를 뽑는 경우의 수는 i개
		arr[i][0] = 1; // i개 중 1개도 선택하지 않는 경우의 수는 1개
		arr[i][i] = 1; // i개 중 i개를 선택하는 경우의 수는 1개
	}

}

int main()
{
	int N, K;
	cin >> N >> K;
	DP_Initialiaztion();

	// 점화식으로 배열 완성하기
	// i가 2부터 시작하는 이유
	// i가 1일 경우는 초기화가 되어있음
	for (int i = 2; i <= N; i++) { 
		for (int j = 1; j < i ; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}

	cout << arr[N][K]; // 결과 출력하기

	return 0;
}
