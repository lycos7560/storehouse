#include <iostream>
#include <algorithm> // �˰����� ������ ���ؿ��� ������ ����

using namespace std;

// �� ���ڿ��� �����ִ� �Լ�
string SumString(string strA, string strB)
{
	string tempStr;

	// �� ���ڿ� �߿��� ���� ���� �ε��� ���� ã��
	int maxLength = strA.length() > strB.length() ? strA.length() : strB.length();

	// ���ڿ��� ������ �ش�.
	reverse(strA.begin(), strA.end()); 
	reverse(strB.begin(), strB.end());

	// ������ �� ���ڿ��� �ε����� ���߾� �ش�.
	for (int i = strA.length(); i < maxLength; i++) { strA.push_back('0'); }
	for (int i = strB.length(); i < maxLength; i++) { strB.push_back('0'); }

	int tempOne, tempTwo, tempThree;
	int up = 0; 

	// ���� �ε����� char�� int�� ��ȯ�ϰ� ���� �� ���ش�.
	// ���� up ������ �ø� ó���� ���ش�.
	for (int i = 0; i < maxLength; i++) {
		tempOne = 0;
		tempTwo = 0;
		if (i <= strA.length()) { tempOne = strA[i] - '0'; } // char => int
		if (i <= strB.length()) { tempTwo = strB[i] - '0'; } // char => int
		tempThree = tempOne + tempTwo + up;
		up = 0;

		if (tempThree >= 10) {
			tempThree -= 10;
			up += 1; // �ø�ó��
		}

		tempStr.push_back(tempThree + '0'); // int => char
	}

	if (up >= 1) { tempStr.push_back('1'); } // �ø��� �����ִٸ�
	reverse(tempStr.begin(), tempStr.end()); // ���� ���� ������ �ش�.
	return tempStr;
}

int main()
{
	string tempOne, tempTwo;
	cin >> tempOne >> tempTwo;
	cout << SumString(tempOne, tempTwo);

	return 0;
}