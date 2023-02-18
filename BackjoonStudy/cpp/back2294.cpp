#include <iostream>
#include <algorithm>

using namespace std;

// ������ ��ġ ���� 1 ~ 100   
// �迭�� ���� coin[0 ~ 100]
// coin[N] = N��° ������ ��ġ�� ��Ÿ����.
int coinValue[101]; // ���� {1, 2, 15, 0, 0 ....}

// �־����� ��ǥ ��ġ�� ���� 1 ~ 10,000   
// �迭�� ���� [0 ~ 10,000]
// TargetValue[K] = K��ġ�� ����� ������ �ּ� ����
int TargetValue[10001];

// N ������ ��, K ��ǥ ��ġ
int N, K;

// ������ �ʱ�ȭ ���ִ� ����� �Լ�
void Initialization()
{
	// ������ ��, ��ǥ ��ġ�� �Է¹���
	cin >> N >> K;
	
	// ������ ������� ��ġ�� �Է¹���
	// �ε����z 1������
	int temp = 1;
	while (temp <= N) {
		cin >> coinValue[temp];
		temp++;
	}

	for (int i = 0; i <= K; i++) {
		// ��ǥ ��ġ�� 0�� ��� �ʿ��� ������ ���� 0�� 
		// ��ȭ���� �����Ҷ� �ʿ��ϴ�.
		if (i == 0) { 
			TargetValue[i] = 0; 
			continue;
		}

		// ������ �ּ� ��ġ�� 1
		// �־����� ��ǥ�� ��ġ�� �ִ밪�� 10,000
		// ������ ������ 10,000���� �Ѿ�� ���� ����.
		// �������� �Ұ����� ��츦 -1�� ����Ҷ� �ʿ�
		TargetValue[i] = 10001;
	}

}

int main()
{
	Initialization(); // ���� ������ ����ȭ

	// �Է¹��� ������ ������ŭ ��ȸ
	for (int i = 1; i <= N; i++) {
		// �Է¹��� ��ǥ ��ġ���� ��ȸ
		for (int j = 1; j <= K; j++) {
			
			// ������ ��ġ > ��ǥ�� ��ġ �Ѿ��.
			// TargetValue[K]�� ������ �ʴ´�.
			if (coinValue[i] > j) { continue; }

			// TargetValue[K - coinValue[N] + 1] 
			// ��ǥ ��ġ���� ���� ������ ������ ��ġ�� �ѹ� ���ٸ� �ش� ������ 1�� �߰��� �Ͱ� ����.
			// ������ TargetValue[K]�� ���Ͽ� �� ���� ���� �ִ´�.
			TargetValue[j] = min(TargetValue[j], TargetValue[j - coinValue[i]] + 1);
		}

	}

	// ��ǥ ��ġ�� ������ ������ �������� ����� �����
	// �������� ��ǥ�� ��ġ�� ���� �� ���ٴ� �� => -1�� ���
	if (TargetValue[K] >= 10001) { cout << -1; }
	else { cout << TargetValue[K]; }

	return 0;
}