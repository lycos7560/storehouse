#include <iostream>

using namespace std;

int A, B, C;

// �Է��� �޴� �Լ�
void GetInput()
{
	cin >> A >> B >> C;
}

long long int Calculate(int B)
{
	if (B == 0) { return 1; } //  N ^ 0 = 1
	else if (B == 1) { return (A % C); }
	
	if (B % 2 == 0){ // ¦���� ���
		long long int temp = Calculate(B / 2);
		return (temp * temp) % C;
	}
	else { // Ȧ���� ���
		return (A * Calculate(B-1)) % C;
	}
}

int main()
{
	GetInput();
	cout << Calculate(B);
	return 0;
}