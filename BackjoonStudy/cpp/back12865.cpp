#include <iostream>

using namespace std;

// ������ ���� N�� ������ ���� �ѵ� K
int N, K;

// �������� ���Ը� ����, �������� ��ġ�� ����
int iW[101], iV[101];

// [i][j] 
// i => ������ ���� / j => ������ ����
int arr[101][100001];

void GetInput()
{
	// ������ ������ ������ ���� �ѵ� �Է� �ޱ�
	cin >> N >> K;

	int cnt = 1;
	while (cnt <= N) { // ������ ���Կ� ��ġ�� �Է¹���
		cin >> iW[cnt] >> iV[cnt];
		cnt++;
	}
}

int main()
{
	GetInput();

   for (int i = 1; i <= N; i++) {
       for (int j = 1; j <= K; j++) {
			if (j - iW[i] >= 0) {  // ���� �ѵ� - ���� ������ ���� 
				// ������ ���� �� �ִ� ��� (���� ������ ���)
				
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - iW[i]] + iV[i]);
				// ���߿��� �ִ� ���� ã�� �Լ� max
			}
			else { 
				// ������ ���� �� ���� ��� (���� ������ ����)
				arr[i][j] = arr[i - 1][j];
			}
       }
   }

	// ���������� �����Ѵٸ� arr[N][K] ���� �ִ� ��ġ�� �ȴ�.
	cout << arr[N][K];

	return 0;
}