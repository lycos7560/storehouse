#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX = 101;

constexpr int INF = INT32_MAX;

// 사다리와 뱀을 저장한다.
vector<int> graph[MAX];

// BFS 탐색을 위한 Queue
queue<pair<int,int>> myQueue;

// BFS 탐색에서 주사위의 카운트,
// 방문처리 용도로 사용
int map[MAX];

int N, M, tempO, tempT, result;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
   //cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// 맵을 전부 INF(INT32_MAX)로 변경한다.
	fill(map, map + MAX, INF);

	// 사다리와 뱀의 경로를 넣어준다.
	for (int i = 0; i < N + M; i++) {
		cin >> tempO >> tempT;
		// tempO -> tempT
		graph[tempO].push_back(tempT);
	}

	// 1번에서 시작, 주사위 횟수 0
	myQueue.push(make_pair(1,0));

	while (!myQueue.empty()) {

		int now = myQueue.front().first;
		int cnt = myQueue.front().second;
		myQueue.pop();

		// 결과에 도착했다면 넘어간다.
		if (now == 100) {
			result = cnt;
			break;	
		} 

		for (int i = 1; i <= 6; i++) {

			int tempNow = now + i;

			// 만약 101과 크거나 같다면 넘어간다.
			// 어파치 100에 도착했을때가 큐에 들어가 있어서 
			// 결과에 영향이 없다.
			if (tempNow >= MAX) continue;

			// 해당 칸에 있는 사다리와 뱀을 확인하고 적용한다.
			for (int j = 0; j < graph[tempNow].size(); j++) {
				tempNow = graph[tempNow][j];
			}

			// 해당 칸에 도착할때의 카운트가 기존의 카운트보다 크다면
			// 넘어간다.
			if (map[tempNow] <= cnt + 1) continue;

			map[tempNow] = cnt + 1;
			myQueue.push(make_pair(tempNow, map[tempNow]));
		}
	}

	cout << result;

	return 0;
}