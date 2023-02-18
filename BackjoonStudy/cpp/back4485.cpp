#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

constexpr int MAXN = 125;
constexpr int INF = INT32_MAX;

// 탐색하는 방향 설정 =>  상, 하 ,좌 ,우
int dxdy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int N, nowX, nowY, dcost;

int map[MAXN][MAXN], dis[MAXN][MAXN];

tuple<int, int, int> nowTuple;

// 가중치, x,y 좌표
priority_queue<tuple<int, int, int>> myPQ;

queue<int> resQ;


int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> N; // 테스트 케이스가 0이면 break;
		if (N == 0) break;

		// 2차원 배열 초기화
		// 전체 초기화 : 처음에는 [0][0]을 써주고, 
		// 그 다음 칸에는 [최대 행(값) - 1][최대 열], 다음 칸에는 초기 상태의 값
		// 범위내의 임시 노드를 무한대 변경
		fill(&dis[0][0], &dis[N - 1][N], INF);

		// 테스트 케이스의 입력을 받는다.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		// 우선순위 큐를 이용하기 위하여 음수를 넣는 것을 기억하자
		myPQ.push(make_tuple(-map[0][0], 0, 0));

		while (!myPQ.empty()){

			// 0번 인덱스 가중치, 1번 인덱스 X좌표, 2번 인덱스 Y좌표
			nowTuple = myPQ.top();
			myPQ.pop();

			if (get<1>(nowTuple) == N - 1 && get<1>(nowTuple) == N - 2) break;

			// 상/하/좌/우를 탐색하기 위한 반복문
			for (int i = 0; i < 4; i++) {
				nowX = get<1>(nowTuple) + dxdy[i][0];
				nowY = get<2>(nowTuple) + dxdy[i][1];
				dcost = get<0>(nowTuple) * -1;

				// 문제의 범위를 벗어나는 경우 => 넘어간다.
				if (nowX < 0 || nowY < 0 || nowX >= N || nowY >= N) continue;
				// 현재 위치의 최소 도둑루피 + 다음 칸의 도둑루피의 크기 >= 탐색 위치의 최소 도둑루피
				if (dcost + map[nowX][nowY] >= dis[nowX][nowY]) continue;
				else {
					// 임시 노드 업데이트
					dis[nowX][nowY] = dcost + map[nowX][nowY];
					myPQ.push(make_tuple( -dis[nowX][nowY], nowX, nowY));
				}
			}
		}

		resQ.push(dis[N - 1][N - 1]);
	}

	int cnt = 1;
	while (!resQ.empty()){
		cout << "Problem " << cnt << ": " << resQ.front() << "\n";
		resQ.pop();
		cnt++;
	}

	return 0;
}


