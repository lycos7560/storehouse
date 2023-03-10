#include <iostream>

using namespace std;

constexpr int Max = 1000001;

// 유니온 root노드 배열
int uArr[Max];

int N, M, u, b, c;

//부모를 찾는 함수
//모든 경로가 부모를 가르키게 함
//상수 시간의 복잡도
int Find(int x)
{
	if (uArr[x] == x) return x;
	else return uArr[x] = Find(uArr[x]);
}

//두 노드를 연결 시키는 것
//기준을 정해서 연결시키는 것이 헷갈리지 않음
//작은쪽이 부모 or 큰쪽이 부모
void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y) {
		if (x < y) uArr[y] = x;
		else uArr[x] = y;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	// 유니온 배열 초기화
	for (int i = 0; i <= N; i++) uArr[i] = i;
	
	for (int i = 0; i < M; i++) {

		cin >> u >> b >> c;

		if (u == 0) { // 합집합 연산
			Union(b, c);
		}
		else { // 질의
			if (Find(b) != Find(c)) cout << "NO\n";
			else cout << "YES\n";			
		}	
	}

	return 0;
}