#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAX = 500000;

int arr[MAX];

int N , M, target;

bool BinarySearch(int tArr[MAX], int start, int end, int target)
{
	if (start > end) return false; // 만족하는 결과가 없다 false turn

	int mid = (start + end) / 2; // 중간 값을 찾아준다.

	if (arr[mid] == target)	return true; // 만족하는 결과!! true return

	// 찾는 수가 더 작다면, 검사 범위를 더 작게해서 다시 이분탐색 // 결과가 나오면 return
	// 찾는 수가 더 크면, 검사 범위를 더 크게해서 다시 이분탐색 // 결과가 나오면 return
	if (arr[mid] > target) return BinarySearch(arr, start, mid - 1, target);
	else return BinarySearch(arr, mid + 1, end, target);
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 이분 탐색을 위한 정렬을 수행한다.
	sort(arr, arr + N);

	// 탐색할 숫자의 개수를 입력받는다.
	cin >> M;

	for (int i = 0; i < M; i++) {
		
		cin >> target;
		
		// 이진 탐색 후 출력
		cout << BinarySearch(arr, 0, N - 1, target) << "\n";

	}

	return 0;
}
