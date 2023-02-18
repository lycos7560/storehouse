#include <iostream>
#include <deque>

using namespace std;

/*
*
push_front X: ���� X�� ���� �տ� �ִ´�.

push_back X: ���� X�� ���� �ڿ� �ִ´�.

pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. 
����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. 
����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

size: ���� ����ִ� ������ ������ ����Ѵ�.

empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.

front: ���� ���� �տ� �ִ� ������ ����Ѵ�. 
���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. 
���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

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
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N-- > 0) {
		cin >> str;
		myDeque(str);
	}

	return 0;
}