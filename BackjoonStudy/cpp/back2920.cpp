#include <iostream>

using namespace std;

int arr[8];
string str[3] = { "ascending", "descending", "mixed" };

int main()
{
	// 8개의 숫자를 차례대로 입력받는다.
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	int cnt = 0;

	for (int i = 0; i < 8; i++) {

		switch (cnt)
		{	
			case 0: // 처음은 오름차순을 체크
				if (arr[i] - i == 1) { continue; } // 오름차순은 arr[i] - i == 1 로 판단 가능
				else if (arr[i] + i == 8) { cnt++; } // 내름차순은 arr[i] + i == 8 로 판단 가능
				else { cnt = 2; }
				break;

			case 1:
				if (arr[i] + i == 8) { continue; } // 내름차순은 arr[i] + i == 8 로 판단 가능
				else { cnt = 2; }
				break;

			default:
				break;
		}

	}

	cout << str[cnt];
}