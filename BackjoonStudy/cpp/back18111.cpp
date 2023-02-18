#include <iostream>

using namespace std;

constexpr auto MAX = 500;

int map[MAX][MAX];

// N ����, M ����, B �κ��丮�� �� ����, area ���� ����, MB ���� ������ ��
int N, M, B, Area, MB;

// �ð��� ���̸� ����
pair<int, int> result;

bool debug = false;

// ������ �Է��� �޴� �Լ�
void ReceiveInput()
{
	cin >> N >> M >> B;

	MB = 0;
	result.first = INT32_MAX;
	result.second = INT32_MAX;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			MB += map[i][j];
		}
	}

	if (debug) {
		cout << "\n----------------- ����� -----------------\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "N : " << N << " M : " << M << " B : " << B << " Area : " << Area << " MB : " << MB << "\n";
	}

	// ���� ���̸� ���
	Area = N * M;
}

// �ùķ��̼��� �����մϴ�.
void Simulation(int target)
{
	// �κ��丮 + ���� ��� ��  ��ǥ�� ���̿� �ʿ��� ���� ����
	if (B + MB < target * Area) { return; }
	int tempTime = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] < target) { // ��ǥ�� ���̰� ���� �ʺ��� ���� ���
				tempTime += (target - map[i][j]) * 1; // ���̸�ŭ �ð��� ������
			}
			else if (map[i][j] > target) { // ��ǥ�� ���̰� ���� �ʺ��� ���� ���
				tempTime += (target - map[i][j]) * -2; // ���̸�ŭ �ð��� ������
			}

		}
	}

	// ���� �� ���⿡ �ɸ��� �ð��� �� ���ٸ� 
	if (result.first > tempTime) { 
		result.first = tempTime; 
		result.second = target;
		// �� ���⿡ �ɸ��� �ð��� ������ ���̰� �� ���� ������ ����� ���
		// ������ ���������� Ȯ���ϱ� ������ ���� ó�� X 
	} 
}


int main()
{
	ReceiveInput();

	int cnt = 256;
	while (cnt >= 0) { // 256 ~ 0 ���� ��ǥ�� �ùķ��̼� �մϴ�.
		Simulation(cnt);
		cnt--;
	}

	cout << result.first << " " << result.second;
	return 0;
}