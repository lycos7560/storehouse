#include <iostream>

using namespace std;

// 알파벳의 등장 인덱스 초기값은 -1
int arr[26];

int main()
{
	for (int i = 0; i < 26; i++) {
		arr[i] = -1; // -1 로 초기화 해준다.
	}

	// 문자열을 입력받는다.
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		// 만약 값이 -1 이 라면 해당 알파벳은 
		// 전에 등장한 적이 없다는 뜻이다.
		// 처음이라면 등장한 인덱스를 대입해준다.
		if (arr[str[i] - 'a'] == -1) { arr[str[i] - 'a'] = i; }
	}

	// 정답을 출력한다.
	for (int i = 0; i < 26; i++) { cout << arr[i] << " "; }

	return 0;
}