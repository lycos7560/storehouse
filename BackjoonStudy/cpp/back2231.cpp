#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str = "";
int strToInt;

int tempInt, sum, result = 0;
string tempString;


int main()
{
	cin >> str; // 문자열로 입력을 받아놓는다.
	strToInt = stoi(str); // string => int

	// 입력값의 범위가 (1 ~ 1,000,000)이므로
	// M을 이루는 각 자리수의 합은 0이 될 수 없다.
	// 각 자리수의 합이 1 ~ N의 자리수 * 9 까지 모두 확인
	for (int i = 1; i <= str.length() * 9; i++) {
		
		sum = 0;

		tempInt = strToInt - i;

		tempString = to_string(tempInt);

		for (int j = 0; j < tempString.length(); j++) {
			sum += tempString[j] - '0'; // 모든 자리의 합
		}

		if (sum == i) { result = tempInt; } // 같은지 비교
	}

	cout << result;

	return 0;
}