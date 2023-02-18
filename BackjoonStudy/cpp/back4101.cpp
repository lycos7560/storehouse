#include <iostream>

using namespace std;

pair<int, int> tempPiar;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	 // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> tempPiar.first >> tempPiar.second;
		if (tempPiar.first == 0 && tempPiar.second == 0) break;
		else if (tempPiar.first > tempPiar.second) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}

	return 0;
}