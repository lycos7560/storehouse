#include <iostream>
#include <stack>

using namespace std;

/*
* 
push X: ���� X�� ���ÿ� �ִ� �����̴�.

pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. 
���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.

empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.

top: ������ ���� ���� �ִ� ������ ����Ѵ�. 
���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

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
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N-- > 0) {
		cin >> str;
		myStack(str);
	}

	return 0;
}