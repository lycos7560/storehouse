#include <iostream>
#include <stack>

using namespace std;

/*
* 
push X: 정수 X를 스택에 넣는 연산이다.

pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 
만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

size: 스택에 들어있는 정수의 개수를 출력한다.

empty: 스택이 비어있으면 1, 아니면 0을 출력한다.

top: 스택의 가장 위에 있는 정수를 출력한다. 
만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

*/

int N, temp;

string str;
stack<int> myS;

void myStack(string str)
{
	if (str == "push") {
		cin >> temp;
		myS.push(temp);
	}
	else if (str == "pop") {
		if (myS.empty()) {
			cout << -1 << "\n";
		}
		else {
			temp = myS.top();
			myS.pop();
			cout << temp << "\n";
		}
	}
	else if (str == "size") {
		cout << myS.size() << "\n";
	}
	else if (str == "empty") {
		if (myS.empty()) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	else if (str == "top") {
		if (myS.empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << myS.top() << "\n";
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
		myStack(str);
	}

	return 0;
}