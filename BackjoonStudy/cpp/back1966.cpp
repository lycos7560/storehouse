#include <iostream>
#include <queue>
#include <list>

using namespace std;

queue<pair<int, bool>> myQueue; // 프린터 Q
list <int> resList; // 결과를 저장하는 리스트

pair<int, bool> tempPair;

int N, temp , number, target, cnt;

int arr[10]; // [i] i의 중요도를 가진 문서의 개수를 저장 

int main()
{
	cin >> N;
	while (N-- > 0) {
		
		// 초기화
		for (int i = 1; i <= 9; i++) arr[i] = 0;
		while (!myQueue.empty()) myQueue.pop();
		cnt = 1;

		cin >> number >> target;

		for (int i = 0; i < number; i++) {

			cin >> temp;
			arr[temp]++;

			// 목표의 문서를 마킹
			if (target == i) tempPair = make_pair(temp, true);
			else tempPair = make_pair(temp, false);

			myQueue.push(tempPair);
		}

		for (int i = 9; i >= 1; i--) {
			while (arr[i] != 0) { // 상위 중요도 문서부터 문서 개수가 0 이될때까지 실행
				tempPair = myQueue.front();

				if (tempPair.first != i) {
					myQueue.pop();
					myQueue.push(tempPair);
				}
				else 
				{	// 만약 목표로하는 문서일 경우 (마킹된 문서)
					if (tempPair.second == true) {
						resList.push_back(cnt); // 인쇄된 순서를 결과에 저장 
						myQueue.pop();
						arr[i]--;
					}
					else
					{
						arr[i]--;
						cnt++;
						myQueue.pop();
					}
				}
			}
		}
	}

	for (auto it = resList.begin(); it != resList.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}