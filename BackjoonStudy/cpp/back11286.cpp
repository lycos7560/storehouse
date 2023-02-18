#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myPQ;

pair<int, int> tempP;

int N, tempO, tempT;

int main()
{

   ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> tempO;

		if (tempO == 0) {
			if (myPQ.empty()) cout << 0 << "\n";
			else {
				tempP = myPQ.top();
				cout << tempP.first * tempP.second << "\n";
				myPQ.pop();
			}
			continue;
		}

		if (tempO > 0) tempT = 1;
		else tempT = -1;

		myPQ.push(make_pair(abs(tempO), tempT));
	}

	return 0;
}