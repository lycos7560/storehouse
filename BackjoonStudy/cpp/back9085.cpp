#include <iostream>

using namespace std;

int t, n, res, temp;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;
		res = 0;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			res += temp;
		}
		cout << res << "\n";
	}

	return 0;
}