#include <iostream>

using namespace std;

// 시간 : H시 M분
int H, M;

int main()
{
	cin >> H >> M;
	
	// 45분을 빼준다.
	M = M - 45;
	if (M < 0) { // 만약 '분'이 음수라면
		M += 60; // -15 -> 45
		H--; // 시간 -1
	}

	if (H < 0) { // 만약 '시'가 음수라면
		H += 24; // -1 -> 23시
	}

	cout << H << " " << M; // 결과 출력

	return 0;
}