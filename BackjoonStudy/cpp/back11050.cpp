//#include <iostream>
//
//using namespace std;
//
//int N, K;
//
//// ���丮���� ����ϴ� �Լ�
//int factorial(int number)
//{	
//	int result = 1;
//	for (int i = 1; i <= number; i++) {
//		result = result * i;
//	}
//
//	return result;
//}
//
//int main()
//{
//	cin >> N >> K;
//	cout << factorial(N) / (factorial(K) * factorial(N - K));
//	return 0;
//} 

#include <iostream>

using namespace std;

// arr[i][j] 
// i �� ������ ����
// j ��å �� ����
// i ���� j���� �̾����� ���� ��� ��
int arr[11][11];

// DP �迭�� �ʱ�ȭ ���ִ� �Լ�
void DP_Initialiaztion()
{
	for (int i = 1; i < 11; i++) {
		arr[i][1] = i; // i�� �� 1���� �̴� ����� ���� i��
		arr[i][0] = 1; // i�� �� 1���� �������� �ʴ� ����� ���� 1��
		arr[i][i] = 1; // i�� �� i���� �����ϴ� ����� ���� 1��
	}

}

int main()
{
	int N, K;
	cin >> N >> K;
	DP_Initialiaztion();

	// ��ȭ������ �迭 �ϼ��ϱ�
	// i�� 2���� �����ϴ� ����
	// i�� 1�� ���� �ʱ�ȭ�� �Ǿ�����
	for (int i = 2; i <= N; i++) { 
		for (int j = 1; j < i ; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}

	cout << arr[N][K]; // ��� ����ϱ�

	return 0;
}
