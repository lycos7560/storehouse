#include <iostream>

using namespace std;

int weight[51], height[51], ranks[51];

int N, temp;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> weight[i] >> height[i];
	}

	for (int i = 1; i <= N; i++) {

		// ������ N�� ���� ����
		temp = N;

		for (int j = 1; j <= N ; j++) {
			
			// �ڱ� �ڽŰ� ���� ��쿡�� �Ѿ��.
			if (i == j) { continue; }

			// �� ������ ���԰� �� ũ�ų� ���� ��� rank ���
			// �� ������ Ű�� �� ũ�ų� ���� ��� rank ���
			if (weight[i] >= weight[j]) temp--;
			else if (height[i] >= height[j]) temp--;
		}

		ranks[i] = temp;
	}

	for (int i = 1; i <= N; i++) {
		cout << ranks[i] << " ";
	}

	return 0;
}