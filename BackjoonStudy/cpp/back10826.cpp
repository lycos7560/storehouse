#include <iostream>
#include <algorithm>

using namespace std;

int N;

string arr[10001];

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

string FibonacciDP(int N)
{
	arr[0] = "0";
	arr[1] = "1";

	for (int i = 2; i <= N; i++) {
		arr[i] = SumString(arr[i - 1], arr[i - 2]);
	}

	return arr[N];
}

int main()
{
	cin >> N;
	cout << FibonacciDP(N);
	return 0;
}
