#include <iostream>

using namespace std;

long long int N;

int T;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T-- > 0)
	{
		cin >> N;
		while (true) {
			N /= 2;
			if (N == 1) {
				cout << 0 << " " << 1 << "\n";
				break;
			}
			else if (N == 0) {
				cout << 1 << " " << 0 << "\n";
				break;
			}
		}
	}
}
