#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int A, B;
string strA, strB;

int main()
{
	cin >> A >> B;
	strA = to_string(A); // int => string
	strB = to_string(B); // int => string

	reverse(strA.begin(), strA.end()); // ���ڿ� ������
	reverse(strB.begin(), strB.end()); // ���ڿ� ������

	A = stoi(strA); // string => int
	B = stoi(strB); // string => int

	cout << max(A, B); // �� �� �߿��� �ִ밪 ���

	return 0;
}