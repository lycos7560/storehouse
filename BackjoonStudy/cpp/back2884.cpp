#include <iostream>

using namespace std;

// �ð� : H�� M��
int H, M;

int main()
{
	cin >> H >> M;
	
	// 45���� ���ش�.
	M = M - 45;
	if (M < 0) { // ���� '��'�� �������
		M += 60; // -15 -> 45
		H--; // �ð� -1
	}

	if (H < 0) { // ���� '��'�� �������
		H += 24; // -1 -> 23��
	}

	cout << H << " " << M; // ��� ���

	return 0;
}