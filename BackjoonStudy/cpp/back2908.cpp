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

	reverse(strA.begin(), strA.end()); // 문자열 뒤집기
	reverse(strB.begin(), strB.end()); // 문자열 뒤집기

	A = stoi(strA); // string => int
	B = stoi(strB); // string => int

	cout << max(A, B); // 두 값 중에서 최대값 출력

	return 0;
}