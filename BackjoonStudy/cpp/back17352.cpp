#include <iostream>

using namespace std;

constexpr int MAX = 300001;

int N, v, u;

int parent[MAX];

void MakeSet(int n)
{
	for (int i = 1; i <= n; i++)  parent[i] = i;
}

int Find(int x) {

	if (parent[x] != x) parent[x] = Find(parent[x]); // Path compression

	return parent[x];
}

void Unite(int x, int y) {
	int rootX = Find(x);
	int rootY = Find(y);
	parent[rootY] = rootX; // Make rootX the parent of rootY
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	MakeSet(N);
	for (int i = 0; i < N - 2; i++) {
		cin >> v >> u;
		Unite(v, u);
	}

	int first, second = -1;
	first = Find(1);
	for (int i = 2; i <= N; i++) {
		if (Find(i) != first) {
			second = Find(i);
			break;
		}
	}

	cout << first << " " << second;

	return 0;
}