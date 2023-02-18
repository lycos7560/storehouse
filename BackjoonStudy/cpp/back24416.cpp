#include <iostream>

using namespace std;

int N, cntOne, cntTwo;
int arr[41];

/*
fib(n) {
	if (n = 1 or n = 2)
	then return 1;  # �ڵ�1
	else return (fib(n - 1) + fib(n - 2));
}
*/
int FibonacciRecursive(int N) // ��� ȣ����
{
	if (N == 1 || N == 2) { 
		cntOne++; // ī��Ʈ
		return 1; 
	}
	else { 
		return FibonacciRecursive(N - 1) + FibonacciRecursive(N - 2); 
	}
}

/*
fibonacci(n) {
	f[1] <- f[2] <- 1;
	for i <- 3 to n
		f[i] <- f[i - 1] + f[i - 2];  # �ڵ�2
	return f[n];
}
*/
int FibonacciDP(int N) // ���� ���α׷��� ���
{
	arr[1] = arr[2] = 1;
	for (int i = 3; i <= N; i++) {
		cntTwo++; // ī��Ʈ
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	return arr[N];
}


int main()
{
	cin >> N;
	cntOne = 0;
	cntTwo = 0;
	FibonacciRecursive(N); // ���
	FibonacciDP(N); // ���� ���α׷���
	cout << cntOne << " " << cntTwo;
	return 0;
}