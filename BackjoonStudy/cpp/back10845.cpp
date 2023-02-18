#include <iostream>
#include <queue>

using namespace std;

/*
push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. 
���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N-- > 0) {
		cin >> str;
		myQueue(str);
	}

	return 0;
}