#include <iostream>

using namespace std;

int A, B, temp, maxA, minB;


// ��Ŭ���� �˰���
// �ִ�����
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

// �ּҰ����
// �� �� A,B�� ���� ���� �ִ������� ���� ���̴�.
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