#include <iostream>
#include <list>
#include <stack>

using namespace std;

list<int> myList;
list<char> resultList;
stack<int> myStack;

int N, temp;
bool check = true;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		myList.push_back(temp);
	}

	temp = 1;

	for (auto it = myList.begin(); it != myList.end(); it++) {
		
		if (*it >= temp) {
			for (int i = temp; i <= *it; i++) {
				myStack.push(temp);
				resultList.push_back('+');
				temp++;
			}
		}

		if (!myStack.empty() && myStack.top() == *it) {
			myStack.pop();
			resultList.push_back('-');
		}
		else {
			check = false;
			break;
		}
	}

	if (check) {
		for (auto it = resultList.begin(); it != resultList.end(); it++) {
			cout << *it << "\n";
		}
	}
	else {
		cout << "NO";
	}

	return 0;
}