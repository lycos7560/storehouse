#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int N, tempI, tempK, temp, tempJ;
int arr[500001];
int number[8001];
long long int sumAll;
list<float> myList; // 결과를 저장할 리스트
list<float> myList2; 

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);
	sumAll = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i]; // N만큼 입력을 받음
		if (arr[i] > 0) number[arr[i] + 4000]++; // 양수일 경우
		else number[arr[i] * -1]++;
	}
		
	for (int i = 0; i < N; i++)  // 총합을 구함
		sumAll = sumAll + arr[i];

	// 1. 산술평균 : N개의 수들의 합을 N으로 나눈 값
	float tempN = sumAll;
	myList.push_back(floor((tempN / N) + 0.5));

	// 2. 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	sort(arr, arr + N); // 오름차순 정렬

	myList.push_back(arr[(0 + (N))/2]);

	// 3. 최빈값 : N개의 수들 중 가장 많이 나타나는 값
	tempK = 0, tempI = -9999, tempJ = 0;
	int first = 0, second = 0;
	for (int i = 0; i < 8001; i++) {
		if (i <= 4000) {
			if (number[i] > tempI ) {
				tempI = number[i];
				tempK = i * -1;
				myList2.clear();
				myList2.push_back(tempK);
			}
			else if (number[i] == tempI) {
				tempK = i * -1;
				myList2.push_back(tempK);
			}
		}
		else {
				if (number[i] > tempI) {
					tempI = number[i];
					tempN = i - 4000;
					myList2.clear();
					myList2.push_back(tempN);
				}
				else if (number[i] == tempI) {
					tempK = i - 4000;
					myList2.push_back(tempK);
				}
		}
	}

	myList2.sort();

	int size = myList2.size();
	int cnt = 0;

	if (size >= 2) cnt = 2;
	else cnt = 1;

	for (auto it = myList2.begin(); it != myList2.end(); it++) {
		cnt--;
		if (cnt == 0) {
			myList.push_back(*it);
			break;
		}
	}

	// 4. 범위 : N개의 수들 중 최댓값과 최솟값의 차이
	temp = arr[0] - arr[N-1];
	temp = abs(temp);
	myList.push_back(temp);


	// 결과를 출력합니다.
	for (auto it = myList.begin(); it != myList.end(); it++) {
		cout << *it << "\n";
	}

	return 0;
}