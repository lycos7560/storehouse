#include <iostream>

using namespace std;

constexpr int MAX =51;

char map[MAX][MAX];

int N, M, temp, temp2, result = INT32_MAX;

// ������ �Է��� ó���ϴ� �Լ�
void GetInput()
{
	// N X M�� �Է� �޴´�.
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
}

int main()
{
	GetInput(); // ������ �Է��� �޽��ϴ�.

	// ü������ �� �� �ִ� ũ�⸦ ��� üũ�Ѵ�.
	for (int i = 0; i <= N - 8; i++) { // ���� 
		for (int j = 0; j <= M - 8; j++) { // ���� 

			// ü������ ������ �̵��ϸ� �ʱ�ȭ ���ش�.
			temp = 0;
			temp2 = 0;

			for (int k = 1; k <= 8; k++) { 	// ü��ĭ�� 8 x 8
				for (int l = 1; l <= 8; l++) { // �ε��� + ü������ ������ġ

					// ���� ���
					// �ε����� ���� ¦���� ��ġ�� W ��� 
					// �ε����� ¦���� �׻� 'W'�� ���;� �Ѵ�.
					// Ȧ���� 'B'
					if ((k + l) % 2 == 0 && map[k + i][l + j] == 'W') { } 
					else if ((k + l) % 2 == 1 && map[k + i][l + j] == 'B') { }
					else { temp++; } // temp

					// ������ ���� ���� �ݴ��� ��쵵 üũ
					if ((k + l) % 2 == 0 && map[k + i][l + j] == 'B') { }
					else if ((k + l) % 2 == 1 && map[k + i][l + j] == 'W') { }
					else { temp2++; } // temp2

				}
			}

			result = min(temp, result); // W�� �����Ҷ� ĥ�ؾ��ϴ� �ּڰ�
			result = min(temp2, result); // B�� �����Ҷ� ĥ�ؾ��ϴ� �ּڰ�

		}
	}

	cout << result; // ����� ������ش�.

	return 0;
}