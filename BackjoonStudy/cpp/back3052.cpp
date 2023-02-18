#include <iostream>
#include <list>

using namespace std;

int arr[10];
int mod[42];


int main()
{
	int result = 0;

	// 10개의 수를 입력 받습니다.
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	
	// mod[i] 는 나머지가 i인 경우 mod[i]에 ++ 로 추가합니다.
	for (int i = 0; i < 10; i++) {
		mod[arr[i] % 42] ++;
	}

	// mod[i] 가 0보다 크다면 나머지가 i인 경우의 수가 있다는 뜻이므로
	// 결과값을 증가시켜줍니다.
	for (int i = 0; i < 42; i++) {
		if (mod[i] > 0) {
			result++;
		}
	}

	cout << result; //문제의 결과를 출력합니다.

	return 0;
}