#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 501;

int disArr[MAXN];

int TC, N, M, W, S, E, T;

vector<pair<int, int>> graph[MAXN];

bool BellmanFord()
{
	cin >> N >> M >> W;

	vector<pair<int, int>> graph[MAXN];

	// 도로의 정보를 입력받는다.
	for (int i = 0; i < M; i++) {
		cin >> S >> E >> T;
		// 양방향
		graph[S].push_back(make_pair(E, T));
		graph[E].push_back(make_pair(S, T));
	}

	// 웜홀의 정보를 입력받는다.
	for (int i = 0; i < W; i++) {
		cin >> S >> E >> T;
		// 단방향
		graph[S].push_back(make_pair(E, -T));
	}

	// 출발은 어디에새 해도 상관이 없다.
	fill(disArr, disArr + MAXN, 0);

	// (모든 정점의 수 - 1) 번 확인한다.
	// N 번은 순환 체크
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) { // 시작 정점
			for (int j = 0; j < graph[i].size(); j++) {
				int v = graph[i][j].first; // 도착점
				int weight = graph[i][j].second; // 가중치
	
				// 시작 임시 배열의 가중치가 도착지의 가중치보다 크다면
				if (disArr[i] + weight < disArr[v]) {
					disArr[v] = disArr[i] + weight;

					// K == N 일때 새로 업데이트 된다는 의미
					if (k == N) return true; // 순환이 있음
					
				}
			}
		}
	}

	return false;
	// 순환이 없음
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> TC;

	for (int i = 0; i < TC; i++) {

		if (BellmanFord()) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}