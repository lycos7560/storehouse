#include <iostream>
#include <algorithm>

using namespace std;

string str;

int arr[3];

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 3; i++) cin >> arr[i];

	sort(arr, arr + 3);

	for (int i = 0; i < 3; i++) cout << arr[i] << " ";

	return 0;
}