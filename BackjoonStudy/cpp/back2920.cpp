#include <iostream>

using namespace std;

int arr[8];
string str[3] = { "ascending", "descending", "mixed" };

int main()
{
	// 8���� ���ڸ� ���ʴ�� �Է¹޴´�.
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	int cnt = 0;

	for (int i = 0; i < 8; i++) {

		switch (cnt)
		{	
			case 0: // ó���� ���������� üũ
				if (arr[i] - i == 1) { continue; } // ���������� arr[i] - i == 1 �� �Ǵ� ����
				else if (arr[i] + i == 8) { cnt++; } // ���������� arr[i] + i == 8 �� �Ǵ� ����
				else { cnt = 2; }
				break;

			case 1:
				if (arr[i] + i == 8) { continue; } // ���������� arr[i] + i == 8 �� �Ǵ� ����
				else { cnt = 2; }
				break;

			default:
				break;
		}

	}

	cout << str[cnt];
}