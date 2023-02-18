#include <iostream>
#include <vector>

using namespace std;

constexpr long long int INF = INT64_MAX;

constexpr int MAXN = 101;

vector<pair<int, int>> graph[MAXN];

long long int disArr[MAXN];

// N : 지점의 개수, M : 골목길의 개수
int N, M, u, v, w;

int trace[MAXN];

int main()
{

	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;

	fill(disArr, disArr + MAXN, INF);

	disArr[1] = 0;

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		// 단방향
		graph[u].push_back(make_pair(v, -w));
	}


	// (모든 정점의 수 - 1) 번 확인한다.
	// N 번은 순환 체크
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {

				int u = i; // 시작점
				int v = graph[i][j].first; // 도착점
				int weight = graph[i][j].second; // 가중치

				// 만약 임시 배열이 무한대가 아니고 &&
				// 시작 임시 배열의 가중치가 도착지의 가중치보다 크다면
				if (disArr[u] != INF && disArr[u] + weight < disArr[v]) {
					disArr[v] = disArr[u] + weight;
					trace[v] = u;

					// K == N 일때 새로 업데이트 된다는 의미는 
					// 사이클에 포함되거나 사이클에서 도착 지점으로 도달 가능
					// 다음의 disArr[N] == -INF 코드를 통하여 영향이 있는 경로인지 판별 
					if (k == N) disArr[v] = -INF;
					// -INF로 더이상 업데이트를 막는다.
				}
			}
		}
	}

	if (disArr[N] == INF || disArr[N] == -INF) cout << "-1";
	else {
		// 경로를 역으로 추적한다.
		int now = N;
		vector<int> myV;
		while (now != 0) {
			myV.push_back(now);
			now = trace[now]; 
		}

		for (auto it = myV.rbegin(); it != myV.rend(); ++it) cout << *it << " ";

	}

	return 0;
}