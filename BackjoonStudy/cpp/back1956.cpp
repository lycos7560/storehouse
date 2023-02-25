#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = INT32_MAX / 2; 

constexpr int MAX = 401;

vector<pair<int, int>> graph[MAX];

int disArr[MAX][MAX]; // 400 * 10,000  오버 플로우 없음

// V 개의 마을, E 개의 도로
int V, E, a, b, c;

int main()
{
    ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
    // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    // 도로의 정보를 입력
    for (int i = 0; i < E; i++) {

        cin >> a >> b >> c;
        // 일방통행
        graph[a].push_back(make_pair(b, c));

    }

    // 최단 거리 배열 disArr 배열을 INF 초기화
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {

            if (i == j) disArr[i][j] = 0;
            else disArr[i][j] = INF;

        }
    }

    // 경로 가중치 입력
    for (int i = 1; i <= V; i++) { // 시작 정점
        for (int j = 0; j < graph[i].size(); j++) {

            int v = graph[i][j].first; // 도착점
            int weight = graph[i][j].second; // 가중치

            if (disArr[i][v] > weight) disArr[i][v] = weight;
        }
    }

    // 플로이드 워셜
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (i == j) continue;
                else disArr[i][j] = min(disArr[i][j], disArr[i][k] + disArr[k][j]);
            }
        }
    }
    
    int result = INF;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            // 출발 지점과 도착 지점이 같거나 둘중 하나라도 가중치가 무한대라면 넘어간다. 
            if (i == j || disArr[i][j] == INF || disArr[j][i] == INF) continue;
            // 최소 가중치를 찾는다.
            result = min(result, disArr[i][j] + disArr[j][i]);            
        }
    }

    if (result == INF) cout << "-1";
    else cout << result;

    return 0;
}