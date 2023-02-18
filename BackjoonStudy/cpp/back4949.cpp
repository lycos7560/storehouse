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
		if (str == ".") break; // �ʱ�ȭ
		check = true; // �ʱ�ȭ

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') myStack.push(str[i]);
			else if (str[i] == ')' || str[i] == ']') {
				if (myStack.empty()) {  // stack�� ��� �ִµ� ) ] �� ���� �� ����.
					check = false; // ������ �̷��� ����
					break;
				}

				if (str[i] == ')' && myStack.top() == '(') myStack.pop();
				else if (str[i] == ']' && myStack.top() == '[') myStack.pop();
				else check = false;  // ������ �̷��� ����
			}
		}

		if (myStack.empty() && check) myList.push_back("yes");
		else myList.push_back("no");

		while (!myStack.empty()) myStack.pop(); // stack �ʱ�ȭ

	}

	// �Ǻ��� ����� ����մϴ�.
	for (auto it = myList.begin(); it != myList.end(); it++) cout << *it << "\n";

	return 0;
}