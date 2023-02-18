#include <iostream>
#include <list>

using namespace std;

list<pair<int, int>> testCaseList;

// arr[14][14]까지 이용  14층 14호
// arr[i][j]  i => 층 // j => 호
int arr[15][15];

// 문제의 입력을 처리하는 함수
void GetInput()
{
	int N;
	cin >> N;
	pair<int, int> tempPair;

	while (N-- > 0) {
		cin >> tempPair.first >> tempPair.second;
		testCaseList.push_back(tempPair);
	}
}

// DP 배열을 초기화 해주는 함수
void DP_Initialization()
{
	// 0 ~ 14층 => 모든 층의 1호를 1로 초기화
	for (int i = 0; i <= 14; i++) { arr[i][1] = 1; }
	// 0층 1 ~ 14호 => N호를 N명으로 초기화 // 1호는 위에서 함
	for (int i = 2; i <= 14; i++) { arr[0][i] = i; }
}

int main()
{
	GetInput(); // 입력
	DP_Initialization(); // DP 배열 초기화

	// arr[i][j] = arr[i][j-1] + arr[i-1][j]
	for (int i = 1; i <= 14; i++) { // 0 층은 초기화에서 함
		for (int j = 2; j <= 14; j++) { // 1호는 초기화에서 함
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}

	// 테스트 케이스만큼 순회
	for (auto i = testCaseList.begin(); i != testCaseList.end(); i++) {
		// arr[층][호] = 몇 명이 살고 있는가? 
		cout << arr[i->first][i->second] << "\n";
	}
	
	return 0;
}
