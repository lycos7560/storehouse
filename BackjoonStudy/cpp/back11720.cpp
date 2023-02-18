#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N =0 , sum = 0;
	string str = "";
	
	cin >> N;

	cin.ignore(); 
	// 입력 버퍼에 있는 모든 내용을 추출해서 버린다.

	getline(cin, str);
	// 2번째 줄을 string으로 받아준다.

	// 인덱스 순회
	for (int i = 0; i < N; i++) {
		sum += str[i] - '0'; // char => int
	}

	cout << sum;

	return 0;
}