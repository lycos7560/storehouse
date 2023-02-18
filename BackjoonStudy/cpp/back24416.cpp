#include <iostream>

using namespace std;

int N, cntOne, cntTwo;
int arr[41];

/*
fib(n) {
	if (n = 1 or n = 2)
	then return 1;  # 코드1
	else return (fib(n - 1) + fib(n - 2));
}
*/
int FibonacciRecursive(int N) // 재귀 호출방법
{
	if (N == 1 || N == 2) { 
		cntOne++; // 카운트
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
		f[i] <- f[i - 1] + f[i - 2];  # 코드2
	return f[n];
}
*/
int FibonacciDP(int N) // 동적 프로그래밍 방법
{
	arr[1] = arr[2] = 1;
	for (int i = 3; i <= N; i++) {
		cntTwo++; // 카운트
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	return arr[N];
}


int main()
{
	cin >> N;
	cntOne = 0;
	cntTwo = 0;
	FibonacciRecursive(N); // 재귀
	FibonacciDP(N); // 동적 프로그래밍
	cout << cntOne << " " << cntTwo;
	return 0;
}