#include <iostream>
#include <algorithm>

using namespace std;

long long int arr[10001];

long long int K, N, top,temp, result;

// 이진탐색을 실행하는 함수
void BinarySearch(long long int start, long long int end)
{
	if (start >= end) return;

	long long int mid = ((start + end) / 2);

	temp = 0;
	for (int i = 1; i <= K; i++) temp += (arr[i] / mid);
	
	if (temp < N) {
		BinarySearch(start, mid);
	}
	else {
		result = max(mid, result);
		BinarySearch(mid + 1, end);
	}

}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;

	for (int i = 1; i <= K; i++) {
		cin >> arr[i];
		if (top < arr[i]) top = arr[i]; // 가장 큰 수를 찾는다.
	}

	// 이분 탐색 시작
	BinarySearch(1, top + 1);

	cout << result;

	return 0;
}