#include <iostream>

using namespace std;

int N, temp = 1, result = 1;

int main()
{
	cin >> N;

	// 예외 처리
	N -= temp;
	temp += 5;

	while (N > 0) { // 0 보다 작아진다면 진행 X 
		result++; // 카운트를 늘려주고
		N -= temp;
		temp += 6;
	}

	cout << result;

	return 0;
}