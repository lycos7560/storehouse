#include <iostream>
#include <list>

using namespace std;

list<pair<int, int>> testCaseList;

// arr[14][14]���� �̿�  14�� 14ȣ
// arr[i][j]  i => �� // j => ȣ
int arr[15][15];

// ������ �Է��� ó���ϴ� �Լ�
void GetInput()
{
	int N;
	cin >> N;
	pair<int, int> tempPair;

	while (N-- > 0) {
		cin >> tempPair.first >> tempPair.second;
		testCaseList.push_back(tempPair);
	}
}

// DP �迭�� �ʱ�ȭ ���ִ� �Լ�
void DP_Initialization()
{
	// 0 ~ 14�� => ��� ���� 1ȣ�� 1�� �ʱ�ȭ
	for (int i = 0; i <= 14; i++) { arr[i][1] = 1; }
	// 0�� 1 ~ 14ȣ => Nȣ�� N������ �ʱ�ȭ // 1ȣ�� ������ ��
	for (int i = 2; i <= 14; i++) { arr[0][i] = i; }
}

int main()
{
	GetInput(); // �Է�
	DP_Initialization(); // DP �迭 �ʱ�ȭ

	// arr[i][j] = arr[i][j-1] + arr[i-1][j]
	for (int i = 1; i <= 14; i++) { // 0 ���� �ʱ�ȭ���� ��
		for (int j = 2; j <= 14; j++) { // 1ȣ�� �ʱ�ȭ���� ��
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}

	// �׽�Ʈ ���̽���ŭ ��ȸ
	for (auto i = testCaseList.begin(); i != testCaseList.end(); i++) {
		// arr[��][ȣ] = �� ���� ��� �ִ°�? 
		cout << arr[i->first][i->second] << "\n";
	}
	
	return 0;
}
