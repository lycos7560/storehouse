#include <iostream>
#include <cmath>

using namespace std;

int N, r, c, cnt, result;

// (넓이, 시작 x 좌표 , 시작 y 좌표)
void DivideAndConquer(int w, int x, int y)
{
	if (w == 1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++){
				if (x + i == r && y + j == c ) result = cnt;
				cnt++;
			}
		}
		return;
	}
	
	// R, C 의 위치를 각 4분면으로 나누어서 
	// 해당 위치에 없다면 재귀함수로 진입하지않고 계산으로 시간 단축
	if (result == 0) { // 결과가 정해지면 더이상 진행하지 않는다.
		if (x + pow(2, w - 1) > r && y + pow(2, w - 1) > c) DivideAndConquer(w - 1, x, y); // 2
		else  cnt += pow(pow(2, w - 1), 2);

		if (x + pow(2, w - 1) > r && y + pow(2, w - 1) <= c) DivideAndConquer(w - 1, x, y + pow(2, w - 1)); // 1
		else  cnt += pow(pow(2, w - 1), 2);

		if (x + pow(2, w - 1) <= r && y + pow(2, w - 1) > c) DivideAndConquer(w - 1, x + pow(2, w - 1), y); // 3
		else  cnt += pow(pow(2, w - 1), 2);

		if (x + pow(2, w - 1) <= r && y + pow(2, w - 1) <= c) DivideAndConquer(w - 1, x + pow(2, w - 1), y + pow(2, w - 1)); // 4
		else  cnt += pow(pow(2, w - 1), 2);

	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cnt = 0;
	result = 0;

	cin >> N >> r >> c;
	
	// 분할 정복
	DivideAndConquer(N, 0, 0);

	cout << result;

	return 0;
}
