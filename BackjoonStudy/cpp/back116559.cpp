#include <iostream>

using namespace std;

constexpr int MAX = 100001;

int N, M;

int arr[MAX];

long long int dp[MAX];

pair<int, int> tempP;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[1];
	// 범위내의 구간합을 전부 구해 놓는다.
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 0; i < M; i++) {

		cin >> tempP.first >> tempP.second;

		// 예를 들어 8 - 11의 합은 
		// 1에서 11까지의 합에서 1에서 7까지의 합을 빼주면 된다.
		cout << dp[tempP.second] - dp[tempP.first - 1] << "\n";

	}

	return 0;
}