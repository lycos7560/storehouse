#include <iostream>
#include <string> // getline

using namespace std;

int main()
{
	string str;
	int cnt = 0;

	getline(cin, str); 
	// getline �Լ��� �Է� ��Ʈ������ ���ڵ��� �о
	// ���ڷ� ���� ���ڿ��� ����

	if (str[0] != ' ') { cnt++; }

	for (int i = 1; i < str.length(); i++) {
		if (str[i - 1] == ' ' && str[i] != ' ') cnt++;
	}

	cout << cnt;

	return 0;
}