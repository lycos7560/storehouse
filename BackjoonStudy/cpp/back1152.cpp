#include <iostream>
#include <string> // getline

using namespace std;

int main()
{
	string str;
	int cnt = 0;

	getline(cin, str); 
	// getline 함수는 입력 스트림에서 문자들을 읽어서
	// 인자로 받은 문자열에 저장

	if (str[0] != ' ') { cnt++; }

	for (int i = 1; i < str.length(); i++) {
		if (str[i - 1] == ' ' && str[i] != ' ') cnt++;
	}

	cout << cnt;

	return 0;
}