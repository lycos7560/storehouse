#include <iostream>
#include <queue>

using namespace std;

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 
만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int N, temp;

string str;
queue<int> myQ;

void myQueue(string str)
{
	if (str == "push") {
		cin >> temp;
		myQ.push(temp);
	}
	else if (str == "pop") {
		if (myQ.empty()) {
			cout << -1 << "\n";
		}
		else {
			temp = myQ.front();
			myQ.pop();
			cout << temp << "\n";
		}
	}
	else if (str == "size") {
		cout << myQ.size() << "\n";
	}
	else if (str == "empty") {
		if (myQ.empty()) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	else if (str == "front") {
		if (myQ.empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << myQ.front() << "\n";
		}
	}
	else {
		if (myQ.empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << myQ.back() << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N-- > 0) {
		cin >> str;
		myQueue(str);
	}

	return 0;
}