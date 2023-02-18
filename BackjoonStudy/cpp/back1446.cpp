#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 10001;

// 지름길의 개수 N, 고속도로의 길이 D
int N, D;

int A, B, C;

/*
각 노드에 연결되어 있는 노드에 대한 정보를 담는 벡터
a번 노드에서 b번 노드로 가는 비용이 c라는 의미
graph[a].push_back({b, c});
*/
vector<pair<int, int>> graph[MAXN];

// 임시 노드
int dist[MAXN];

int main()
{
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	// scanf와 동기화를 비활성화
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		cin >> A >> B >> C;
		graph[A].push_back(make_pair(B, C));
	}

	// 기본 초기화
	for (int i = 0; i < MAXN; i++) dist[i] = i;

	int now = 0;
	while (true) {

		if (now == D) { 
			// 목적지에 도착했으므로 결과를 출력
			cout << dist[now];
			break;
		}

		// 해당 노드에서 연결된 모든 경로를 확인
       for (int i = 0; i < graph[now].size(); i++) {

           // disSum = 임시 노드 + 현재 노드에서 i로가는 비용
           int disSum = dist[now] + graph[now][i].second;
			
			// 역주행을 해야할 경우는 continue
			if (disSum > D) continue; 


           // 비용이 더 작다면 최단경로 테이블 값을 갱신.
           if (disSum < dist[graph[now][i].first]) {
               // 임시 노드 업데이트
				dist[graph[now][i].first] = disSum;

				// 만약 업데이트 했다면 그 이후의 정점들을 순차적으로 올려준다.
				for (int j = graph[now][i].first + 1; j <= D ; j++) {
					// 만약  dist[j]이 더 작거나 같다면 최단거리가 있다는 의미 => Break
					if (disSum >= dist[j]) break;
					else dist[j] = ++disSum;
				}
           }
       }

		now++;
	}

	return 0;
}