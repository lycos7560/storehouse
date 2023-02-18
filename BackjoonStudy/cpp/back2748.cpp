#include <iostream>

using namespace std;

int N;

// N이 90일 경우 int로 처리하면 
// 21억을 넘어가서 오버플로우가 발생한다. 
long long int arr[91];

long long int FibonacciDP(int N)
{
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	return arr[N];
}

int main()
{
	cin >> N;
	cout << FibonacciDP(N);
	return 0;
}