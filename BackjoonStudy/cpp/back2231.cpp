#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str = "";
int strToInt;

int tempInt, sum, result = 0;
string tempString;


int main()
{
	cin >> str; // ���ڿ��� �Է��� �޾Ƴ��´�.
	strToInt = stoi(str); // string => int

	// �Է°��� ������ (1 ~ 1,000,000)�̹Ƿ�
	// M�� �̷�� �� �ڸ����� ���� 0�� �� �� ����.
	// �� �ڸ����� ���� 1 ~ N�� �ڸ��� * 9 ���� ��� Ȯ��
	for (int i = 1; i <= str.length() * 9; i++) {
		
		sum = 0;

		tempInt = strToInt - i;

		tempString = to_string(tempInt);

		for (int j = 0; j < tempString.length(); j++) {
			sum += tempString[j] - '0'; // ��� �ڸ��� ��
		}

		if (sum == i) { result = tempInt; } // ������ ��
	}

	cout << result;

	return 0;
}