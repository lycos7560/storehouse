#include <iostream>
#include <algorithm>

using namespace std;

int N;

string arr[10001];

// 두 문자열을 더해주는 함수
string SumString(string strA, string strB)
{
	string tempStr;

	// 두 문자열 중에서 가장 높은 인덱스 길이 찾음
	int maxLength = strA.length() > strB.length() ? strA.length() : strB.length();

	// 문자열을 뒤집어 준다.
	reverse(strA.begin(), strA.end()); 
	reverse(strB.begin(), strB.end());

	// 뒤집은 두 문자열의 인덱스를 맞추어 준다.
	for (int i = strA.length(); i < maxLength; i++) { strA.push_back('0'); }
	for (int i = strB.length(); i < maxLength; i++) { strB.push_back('0'); }

	int tempOne, tempTwo, tempThree;
	int up = 0; 

	// 같은 인덱스의 char를 int로 변환하고 서로 더 해준다.
	// 만약 up 변수로 올림 처리를 해준다.
	for (int i = 0; i < maxLength; i++) {
		tempOne = 0;
		tempTwo = 0;
		if (i <= strA.length()) { tempOne = strA[i] - '0'; } // char => int
		if (i <= strB.length()) { tempTwo = strB[i] - '0'; } // char => int
		tempThree = tempOne + tempTwo + up;
		up = 0;

		if (tempThree >= 10) {
			tempThree -= 10;
			up += 1; // 올림처리
		}

		tempStr.push_back(tempThree + '0'); // int => char
	}

	if (up >= 1) { tempStr.push_back('1'); } // 올림이 남아있다면
	reverse(tempStr.begin(), tempStr.end()); // 더한 값을 뒤집어 준다.
	return tempStr;
}

string FibonacciDP(int N)
{
	arr[0] = "0";
	arr[1] = "1";

	for (int i = 2; i <= N; i++) {
		arr[i] = SumString(arr[i - 1], arr[i - 2]);
	}

	return arr[N];
}

int main()
{
	cin >> N;
	cout << FibonacciDP(N);
	return 0;
}
