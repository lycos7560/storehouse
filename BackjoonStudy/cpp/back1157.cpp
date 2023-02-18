#include <iostream>
#include <algorithm>

using namespace std;

string str;

int arr[26]; // 알파벳의 개수는 26개

int main()
{
	// 문제의 문자열을 받는다.
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 97) 	arr[(str[i] - 32) - 'A']++; // 소문자
		else arr[str[i] - 'A']++; // 대문자
	}

	// 가장 많이 사용한 알파벳을 찾는다.
	int maxIndex = -1;
	int max = -1;
	for (int i = 0; i < 26; i++) {
		if (max < arr[i]) {
			max = arr[i];
			maxIndex = i;
		}
	}

	// 가장많이 사용한 알파벳을 출력한다.
	sort(arr, arr + 26, greater<int>()); // 내림차순 정렬

	// 0번과 1번이 같다면 가장 많이 사용된 알파벳이 한개가 아니라는 의미 
	if (arr[0] == arr[1]) {
		cout << "?"; 
	}
	else { 
		char ch = maxIndex + 'A'; 
		cout << ch;
	} 

	return 0;
}