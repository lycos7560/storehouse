#include <iostream>

using namespace std;

int value[10]; // ������ ��ġ�� ������ �迭

int N, K, temp,  cnt = 0;

int main()
{
	cin >> N >> K;

	// �迭�� ������ ��ġ�� �־� �д�.
	for (int i = 0; i < N; i++) cin >> value[i];

	// ���� ū �������� ��
	for (int i = N - 1; i >= 0; i--) {

		// K�� 0�̶�� ���� �޼� break
		if (K == 0) break;
		
		temp = K / value[i];

		if (temp > 0) {
			cnt += temp;
			K -= temp * value[i];
		}
		else continue;
		// ������ ��ġ�� ���� ��ǥ���� ũ�ٸ� continue;
	}

	// ����� ����Ѵ�.
	cout << cnt;

	return 0;
}