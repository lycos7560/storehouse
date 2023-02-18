#include <iostream>
#include <list>

using namespace std;

list<string> myList;
string answer[2] = { "NO","YES" };
string temp;
int N, check;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		myList.push_back(temp);
	}

	for (auto it = myList.begin();  it != myList.end(); it++) {
		temp = *it;
		check = 1;
		N = 0;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == '(') { N++; }
			else { N--; }
			if (N < 0) { check = 0; } // �ѹ��̶�� ������ �������� �ȵ� => NO
		}

		if (N != 0) check = 0; // ��ȸ�� ������ N�� ����� (�� �����ִ�. => NO

		cout << answer[check] << "\n";
	}

	return 0;
}