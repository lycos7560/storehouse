#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = INT32_MAX/2;

constexpr int MAX = 101;

vector<pair<int, int>> graph[MAX];

int disArr[MAX][MAX];

// N : 도시의 수, M : 버스의 수
int N, M, s, d, w;

int main()
{	
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// 노선을 입력
	for (int i = 0; i < M; i++) {

		// 단방향 교통수단 출발 s, 도착 d, 비용 w
		cin >> s >> d >> w;

		graph[s].push_back(make_pair(d, w));
	}

	// 최단 거리 배열 disArr 배열을 INF 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (i == j) disArr[i][j] = 0;
			else disArr[i][j] = INF;

		}
	}

	for (int i = 1; i <= N; i++) { // 시작 정점
		for (int j = 0; j < graph[i].size(); j++) {

			int v = graph[i][j].first; // 도착점
			int weight = graph[i][j].second; // 가중치

			if (disArr[i][v] > weight) 	disArr[i][v] = weight;

		}
	}
	
	// 무지성 플로이드
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (i == j) disArr[i][j] = 0;
				else disArr[i][j] = min(disArr[i][j], disArr[i][k] + disArr[k][j]);

			}
		}
	}

	// 결과 출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (disArr[i][j] == INF) cout << 0 << " ";
			else cout << disArr[i][j] << " ";

		}

		cout << "\n";

	}

	return 0;
}