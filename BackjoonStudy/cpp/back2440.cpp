#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	string str;

	for (int i = 0; i < N; i++) str.push_back('*');
	while (N-- > 0) {
		for (int i = N; i >= 0; i--)
			cout << str[i];

		cout << "\n";
	}

	return 0;
}