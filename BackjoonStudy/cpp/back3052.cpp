#include <iostream>
#include <list>

using namespace std;

int arr[10];
int mod[42];


int main()
{
	int result = 0;

	// 10���� ���� �Է� �޽��ϴ�.
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	
	// mod[i] �� �������� i�� ��� mod[i]�� ++ �� �߰��մϴ�.
	for (int i = 0; i < 10; i++) {
		mod[arr[i] % 42] ++;
	}

	// mod[i] �� 0���� ũ�ٸ� �������� i�� ����� ���� �ִٴ� ���̹Ƿ�
	// ������� ���������ݴϴ�.
	for (int i = 0; i < 42; i++) {
		if (mod[i] > 0) {
			result++;
		}
	}

	cout << result; //������ ����� ����մϴ�.

	return 0;
}