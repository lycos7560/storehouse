#include <iostream>

using namespace std;

int T, N, M, x, y, result, temp;

// 유클리드 호제법(최대 공약수 구하기)
int gcd(int a, int b) 
{
	return b ? gcd(b, a % b) : a;
}

// 최소 공배수 구하기
int LCM(int a , int b) {
	return a * b / gcd(a, b);
}

int main()
{
	cin >> T;

	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	while (T-- > 0) {

		cin >> N >> M >> x >> y;

		result = -1;

		for (int i = x; i <= LCM(N, M); i += N) {

			if (i % M == 0) temp = M;
			else temp = i % M;

			if (temp == y) {
				result = i;
				break;
			}
		}

		if (result > 0) cout << result << "\n";
		else cout << -1 << "\n";
	}

	return 0;
}