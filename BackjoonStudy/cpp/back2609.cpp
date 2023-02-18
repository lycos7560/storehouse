#include <iostream>

using namespace std;

int A, B, temp, maxA, minB;


// 유클리드 알고리즘
// 최대공약수
int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

// 최소공배수
// 두 수 A,B를 곱한 값을 최대공약수로 나눈 값이다.
int lcm(int a, int b) {

	return (a * b) / gcd(a, b);
}

int main()
{
	cin >> A >> B;
	cout << gcd(A, B) << "\n";
	cout << lcm(A, B);

	return 0;
}