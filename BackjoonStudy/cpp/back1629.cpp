#include <iostream>

using namespace std;

int A, B, C;

// 입력을 받는 함수
void GetInput()
{
	cin >> A >> B >> C;
}

long long int Calculate(int B)
{
	if (B == 0) { return 1; } //  N ^ 0 = 1
	else if (B == 1) { return (A % C); }
	
	if (B % 2 == 0){ // 짝수일 경우
		long long int temp = Calculate(B / 2);
		return (temp * temp) % C;
	}
	else { // 홀수일 경우
		return (A * Calculate(B-1)) % C;
	}
}

int main()
{
	GetInput();
	cout << Calculate(B);
	return 0;
}