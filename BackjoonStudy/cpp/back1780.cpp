#include <iostream>
#include <cmath>

using namespace std;

constexpr int MAX = 2187;

int map[MAX][MAX];

int N;

// 0 = 0 / 1 = 1 / -1 = 2
int result[3];

void ConquestDivison(int x, int y, int w)
{
	// 종이의 길이가 1(3^0) 이라면 해당 종이의 카운트를 증가시켜 줍니다.
	if (w == 0) { 
		if (map[x][y] == -1) result[2]++;
		else result[map[x][y]]++;
		return;
	}

	int number = map[x][y];
	int temp = pow(3, w);
	bool check = true;
	for (int i = 0; i < temp; i++) {
		for (int j = 0; j < temp; j++) {
			// 모든 부분이 서로 같은지 체크합니다.
			// 다르다면 빠져나가고 마킹해줍니다.
			if (number == map[x + i][y + j]) { continue; }
			else {
				check = false;
				break;
			}
		}
		if (!check) break;
	}

	if (check) { // 모든 부분이 같다면 해강 종이의 카운트를 올려줍니다.
		if (number == -1) result[2]++;
		else result[map[x][y]]++;
		return;
	}
	
	int temp2 = pow(3, w - 1);

	// 분할 정복 9등분
	ConquestDivison(x              , y              , w - 1);
	ConquestDivison(x              , y + temp2      , w - 1);
	ConquestDivison(x              , y + 2 * (temp2), w - 1);

	ConquestDivison(x + temp2	   , y				, w - 1);
	ConquestDivison(x + temp2	   , y + temp2		, w - 1);
	ConquestDivison(x + temp2	   , y + 2 * (temp2), w - 1);

	ConquestDivison(x + 2 * (temp2), y	            , w - 1);
	ConquestDivison(x + 2 * (temp2), y + temp2	    , w - 1);
	ConquestDivison(x + 2 * (temp2), y + 2 * (temp2), w - 1);
}


int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 문제를 입력받습니다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// N이 3의 몇승인지 확인합니다.
	int k = 0;
	int temp = N;
	while (temp != 1) {
		temp /= 3;
		k++;
	}
	
	ConquestDivison(0, 0, k);

	cout << result[2] << "\n" << result[0] << "\n" << result[1];

	return 0;
}