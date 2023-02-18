#include <iostream>

using namespace std;

// 범위는 2^7 = 128
constexpr int MAX = 129;

int N;

// 0 - white, 1 - bule
int result[2];

int map[MAX][MAX];

// (넓이, 시작 x 좌표 , 시작 y 좌표)
void DivideAndConquer(int w, int x, int y)
{
	if (w == 1) { 
		// 넓이가 1이면 해당 시작점 색의 색종이
		result[map[x][y]]++;
		return;
	} 

	int check = 0;

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			 check += map[x + i][y + j];
			 // 범위를 다 더해서 0 이면 하얀색 색종이
			 // W * W 이면 파란색 색종이
		}
	}

	if (check == 0) {
		result[0]++; // 하얀색 색종이 추가
	}
	else if (check == w * w) {
		result[1]++; // 파란색 색종이 추가
	}
	else { // 분할 정복
		DivideAndConquer(w / 2, x , y );
		DivideAndConquer(w / 2, x + w / 2, y );
		DivideAndConquer(w / 2, x        , y  + w / 2);
		DivideAndConquer(w / 2, x + w / 2, y  + w / 2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	// 분할 정복
	DivideAndConquer(N, 1, 1);

	// 결과 출력
	cout << result[0] << "\n" << result[1];

	return 0;
}
