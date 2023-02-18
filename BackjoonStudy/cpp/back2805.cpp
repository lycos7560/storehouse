#include <iostream>

using namespace std;

// 나무의 수 : N , 집으로 가져가려고 하는 나무의 길이 : M
long long int N, M, maxN, result, temp = INT64_MAX;
long long int arr[1000001];

// 이진탐색을 실행하는 함수
void BinarySearch(long long int start, long long int end)
{
	if (start >= end) return;

	long long int mid = ((start + end) / 2);

	temp = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] <= mid) continue; // 톱니의 길이가 나무보다 긴 경우
		temp += (arr[i] - mid);
	}
		
	if (temp >= M) {
		result = max(mid, result);
		BinarySearch(mid + 1, end);
	}
	else {
		BinarySearch(start, mid);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (maxN < arr[i]) maxN = arr[i]; // 최고 값을 찾는다.
	}

	// 1 - Top 탐색 시작
	BinarySearch(1, maxN + 1);

	cout << result;

	return 0;
}