#include <iostream>
#include <stack>

using namespace std;

stack<int> myStack;

int N, temp;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	while (N-- > 0) {
		cin >> temp;
		// �Է��� 0���� Ŭ ��� push
		// ���� ��� pop
		if (temp > 0) myStack.push(temp);
		else myStack.pop();
	}

	temp = 0;

	// stack ������ ���� ���� �� ���ش�.
	while (!myStack.empty()) {
		temp += myStack.top();
		myStack.pop();
	}

	cout << temp;

	return 0;
}