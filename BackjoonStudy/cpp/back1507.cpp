#include <iostream>

using namespace std;

constexpr int MAX = 21;

int disArr[MAX][MAX];

int route[MAX][MAX];

int N, result;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> disArr[i][j];
			route[i][j] = disArr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {

				if (j == k || i == k) continue;

				// 불가능한 경우이므로 -1 출력
				if (disArr[i][j] > disArr[i][k] + disArr[k][j]) {
					cout << "-1";
					return 0;
				}

				// 경로를 지워준다.
				if (disArr[i][j] == disArr[i][k] + disArr[k][j]) route[i][j] = 0;
			}
		}
	}


	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) result += route[i][j];
	
	// 반으로 나누어준다.
	cout << result/2;

	return 0;
}