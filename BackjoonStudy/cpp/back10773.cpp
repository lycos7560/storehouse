#include <iostream>
#include <stack>

using namespace std;

stack<int> myStack;

int N, temp;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	while (N-- > 0) {
		cin >> temp;
		// 입력이 0보다 클 경우 push
		// 작을 경우 pop
		if (temp > 0) myStack.push(temp);
		else myStack.pop();
	}

	temp = 0;

	// stack 내부의 값을 전부 더 해준다.
	while (!myStack.empty()) {
		temp += myStack.top();
		myStack.pop();
	}

	cout << temp;

	return 0;
}