#include <iostream>

using namespace std;

// ���ĺ��� ���� �ε��� �ʱⰪ�� -1
int arr[26];

int main()
{
	for (int i = 0; i < 26; i++) {
		arr[i] = -1; // -1 �� �ʱ�ȭ ���ش�.
	}

	// ���ڿ��� �Է¹޴´�.
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		// ���� ���� -1 �� ��� �ش� ���ĺ��� 
		// ���� ������ ���� ���ٴ� ���̴�.
		// ó���̶�� ������ �ε����� �������ش�.
		if (arr[str[i] - 'a'] == -1) { arr[str[i] - 'a'] = i; }
	}

	// ������ ����Ѵ�.
	for (int i = 0; i < 26; i++) { cout << arr[i] << " "; }

	return 0;
}