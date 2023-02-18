#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];

int N, temp;

int main()
{

	ios_base::sync_with_stdio(false); // 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N-- > 0) {
		cin >> temp;
		arr[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == 0) continue;

		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}

	return 0;
}