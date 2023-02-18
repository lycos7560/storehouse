#include <iostream>
#include <stack>
#include <list>
#include <string>

using namespace std;

stack<char> myStack;
list<string> myList;
string str;
bool check = true;

int main()
{
	while (true)
	{
		getline(cin, str);
		if (str == ".") break; // 초기화
		check = true; // 초기화

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') myStack.push(str[i]);
			else if (str[i] == ')' || str[i] == ']') {
				if (myStack.empty()) {  // stack이 비어 있는데 ) ] 가 나올 수 없다.
					check = false; // 균형을 이루지 않음
					break;
				}

				if (str[i] == ')' && myStack.top() == '(') myStack.pop();
				else if (str[i] == ']' && myStack.top() == '[') myStack.pop();
				else check = false;  // 균형을 이루지 않음
			}
		}

		if (myStack.empty() && check) myList.push_back("yes");
		else myList.push_back("no");

		while (!myStack.empty()) myStack.pop(); // stack 초기화

	}

	// 판별한 결과를 출력합니다.
	for (auto it = myList.begin(); it != myList.end(); it++) cout << *it << "\n";

	return 0;
}