#include <iostream>

using namespace std;

int N, cnt, number, tempNumber;

string str;

int main()
{
	cin >> N;
	cnt = 0;
	number = 665;
	tempNumber = 0;

	// N��°�� ���� ������ �ݺ�
	while (cnt != N) {
		number++;
		tempNumber = number;

		while (tempNumber != 0)
		{
			if (tempNumber % 1000 == 666) {
				cnt++;
				break;
			}
			else tempNumber /= 10;
		}
	}

	cout << number;

	return 0;
}