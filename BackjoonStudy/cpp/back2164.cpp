#include <iostream>
#include <queue>

using namespace std;

int N;

queue<int> myQ;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		myQ.push(i);
	}

	// 큐의 사이즈가 1보다 크다면 반복
	while (myQ.size() > 1) { 
		myQ.pop(); // 가장 위 카드를 버린다. 

		// 그 다음 카드를 다시 큐에 넣는다.
		N = myQ.front(); 
		myQ.pop();
		myQ.push(N);
	}

	// 카드가 한장 남았을 때 값을 출력한다. 
	cout << myQ.front();
	return 0;
}