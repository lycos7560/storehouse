#include <iostream>
#include <deque>

using namespace std;

/*
*
push_front X: 정수 X를 덱의 앞에 넣는다.

push_back X: 정수 X를 덱의 뒤에 넣는다.

pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 
만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 
만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

size: 덱에 들어있는 정수의 개수를 출력한다.

empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.

front: 덱의 가장 앞에 있는 정수를 출력한다. 
만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

back: 덱의 가장 뒤에 있는 정수를 출력한다. 
만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

*/

int N, temp;

string str;
deque<int> myDeq;

void myDeque(string str)
{
	if (str == "push_front") {
		cin >> temp;
		myDeq.push_front(temp);
	}
	else if (str == "push_back") {
		cin >> temp;
		myDeq.push_back(temp);
	}
	else if (str == "pop_front") {
		if (myDeq.empty()) {
			cout << -1 << "\n";
		}
		else {
			temp = myDeq.front();
			myDeq.pop_front();
			cout << temp << "\n";
		}
	}
	else if (str == "pop_back") {
		if (myDeq.empty()) {
			cout << -1 << "\n";
		}
		else {
			temp = myDeq.back();
			myDeq.pop_back();
			cout << temp << "\n";
		}
	}
	else if (str == "size") {
		cout << myDeq.size() << "\n";
	}
	else if (str == "empty") {
		if (myDeq.empty()) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	else if (str == "front") {
		if (myDeq.empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << myDeq.front() << "\n";
		}
	}
	else if (str == "back") {
		if (myDeq.empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << myDeq.back() << "\n";
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
		myDeque(str);
	}

	return 0;
}