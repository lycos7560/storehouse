#include <iostream>

using namespace std;

int N, temp = 1, result = 1;

int main()
{
	cin >> N;

	// ���� ó��
	N -= temp;
	temp += 5;

	while (N > 0) { // 0 ���� �۾����ٸ� ���� X 
		result++; // ī��Ʈ�� �÷��ְ�
		N -= temp;
		temp += 6;
	}

	cout << result;

	return 0;
}