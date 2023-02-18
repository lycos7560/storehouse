#include <iostream>

using namespace std;

int N, M, cnt = 0;

pair<int, int> tempPair;

bool arr[1001][1001];

void CheckNode(int A)
{
	arr[A][0] = false; // 방문처리
	for (int i = 1; i <= N; i++) {
		if (A == i) continue;

		// 양방향 탐색
		if ((arr[i][0] == true && arr[i][A] == true) || (arr[i][0] == true && arr[A][i] == true)) 
			CheckNode(i);
	}
}


int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// 자기 자신은 항상 자기 자신의 연결 요소에 속한다.
	for (int i = 1; i <= N; i++) arr[i][0] = true;


	for (int i = 0; i < M; i++) {
		cin >> tempPair.first >> tempPair.second;
		arr[tempPair.first][tempPair.second] = true;
		arr[tempPair.first][0] = true;
		arr[tempPair.second][0] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (arr[i][0] == false) continue; // 방문처리가 되어있다면 넘어간다.
		else 
		{
			CheckNode(i);
			cnt++; // 연결요소 카운트 + 1
		}
	}

	cout << cnt;

	return 0;
}