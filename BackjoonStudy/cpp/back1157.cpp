#include <iostream>
#include <algorithm>

using namespace std;

string str;

int arr[26]; // ���ĺ��� ������ 26��

int main()
{
	// ������ ���ڿ��� �޴´�.
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 97) 	arr[(str[i] - 32) - 'A']++; // �ҹ���
		else arr[str[i] - 'A']++; // �빮��
	}

	// ���� ���� ����� ���ĺ��� ã�´�.
	int maxIndex = -1;
	int max = -1;
	for (int i = 0; i < 26; i++) {
		if (max < arr[i]) {
			max = arr[i];
			maxIndex = i;
		}
	}

	// ���帹�� ����� ���ĺ��� ����Ѵ�.
	sort(arr, arr + 26, greater<int>()); // �������� ����

	// 0���� 1���� ���ٸ� ���� ���� ���� ���ĺ��� �Ѱ��� �ƴ϶�� �ǹ� 
	if (arr[0] == arr[1]) {
		cout << "?"; 
	}
	else { 
		char ch = maxIndex + 'A'; 
		cout << ch;
	} 

	return 0;
}