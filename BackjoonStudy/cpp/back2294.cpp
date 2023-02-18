#include <iostream>
#include <algorithm>

using namespace std;

// 코인의 가치 범위 1 ~ 100   
// 배열의 범위 coin[0 ~ 100]
// coin[N] = N번째 코인의 가치를 나타낸다.
int coinValue[101]; // 예제 {1, 2, 15, 0, 0 ....}

// 주어지는 목표 가치의 범위 1 ~ 10,000   
// 배열의 범위 [0 ~ 10,000]
// TargetValue[K] = K가치를 만드는 동전의 최소 개수
int TargetValue[10001];

// N 동전의 수, K 목표 가치
int N, K;

// 문제를 초기화 해주는 기능의 함수
void Initialization()
{
	// 동전의 수, 목표 가치를 입력받음
	cin >> N >> K;
	
	// 동전의 순서대로 가치를 입력받음
	// 인덱스틑 1번부터
	int temp = 1;
	while (temp <= N) {
		cin >> coinValue[temp];
		temp++;
	}

	for (int i = 0; i <= K; i++) {
		// 목표 가치가 0인 경우 필요한 동전의 수는 0개 
		// 점화식을 전개할때 필요하다.
		if (i == 0) { 
			TargetValue[i] = 0; 
			continue;
		}

		// 동전의 최소 가치는 1
		// 주어지는 목표의 가치의 최대값은 10,000
		// 동전의 개수가 10,000개를 넘어가는 경우는 없다.
		// 문제에서 불가능한 경우를 -1로 출력할때 필요
		TargetValue[i] = 10001;
	}

}

int main()
{
	Initialization(); // 문제 조건을 조기화

	// 입력받은 동전의 개수만큼 순회
	for (int i = 1; i <= N; i++) {
		// 입력받은 목표 가치까지 순회
		for (int j = 1; j <= K; j++) {
			
			// 코인의 가치 > 목표의 가치 넘어간다.
			// TargetValue[K]가 변하지 않는다.
			if (coinValue[i] > j) { continue; }

			// TargetValue[K - coinValue[N] + 1] 
			// 목표 가치에서 현재 순서의 코인의 가치를 한번 뺀다면 해당 코인을 1개 추가한 것과 같다.
			// 기존의 TargetValue[K]와 비교하여 더 작은 수를 넣는다.
			TargetValue[j] = min(TargetValue[j], TargetValue[j - coinValue[i]] + 1);
		}

	}

	// 목표 가치의 동전의 개수가 범위에서 벗어나는 수라면
	// 동전으로 목표의 가치를 만들 수 없다는 뜻 => -1을 출력
	if (TargetValue[K] >= 10001) { cout << -1; }
	else { cout << TargetValue[K]; }

	return 0;
}