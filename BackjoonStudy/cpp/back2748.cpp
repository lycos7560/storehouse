#include <iostream>

using namespace std;

int N;

// N�� 90�� ��� int�� ó���ϸ� 
// 21���� �Ѿ�� �����÷ο찡 �߻��Ѵ�. 
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