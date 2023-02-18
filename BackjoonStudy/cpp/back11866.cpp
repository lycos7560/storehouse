#include <iostream>
#include <queue>

using namespace std;

int N, K, temp, cnt;

queue<int> myQ;
queue<int> resultQ;

int main()
{

	cin >> N >> K;

	cnt = 1;
	for (int i = 1; i <= N; i++) {

		if (cnt == K) {
			cnt = 1;
			resultQ.push(i);
		}
		else {
			myQ.push(i);
			cnt++;
		}
	}

	while (!myQ.empty()) {

		temp = myQ.front();
		myQ.pop();

		if (cnt == K) {
			cnt = 1;
			resultQ.push(temp);
		}
		else {
			myQ.push(temp);
			cnt++;
		}
	}

	cout << "<";

	while (!resultQ.empty()) {
		cout << resultQ.front();
		resultQ.pop();
		if (resultQ.size() >= 1) {
			cout << ", ";
		}
	}

	cout << ">";
	
	return 0;
}