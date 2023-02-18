#include <iostream>

using namespace std;

constexpr int Max = 100;

int mapA[Max][Max];

int mapB[Max][Max];

int N, M;

int main()
{

	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mapA[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mapB[i][j];
			mapA[i][j] += mapB[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << mapA[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}