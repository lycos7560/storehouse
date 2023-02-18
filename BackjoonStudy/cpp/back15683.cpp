#include <iostream>

using namespace std;

constexpr auto MAX = 8;

int map[MAX][MAX];

// N ����, M ����
int N, M, MinBlindSpot;

bool debugBool = false;

// �� �� �� ��
int dxdy[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

// CCTV�� Ÿ���� �⺻���� -1
struct CCTVInformation
{
	int type = -1;
	int x = 0;
	int	y = 0;

} CCTV[MAX];

// �ð����� ����׿� �Լ�
void DebugPrint()
{
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	for (int i = 0; i < MAX; i++) {
		if (CCTV[i].type != -1)
		{
			cout << "CCTV[i].type : " << CCTV[i].type << " CCTV[i].x : " << CCTV[i].x << " CCTV[i].y : " << CCTV[i].y << "\n";
		}
	}
}

// ���α׷� ���۽� �ʱ�ȭ
void Initialization()
{
	MinBlindSpot = 64;

	// ���� ��� �κ��� �� �������� �ʱ�ȭ �����ݴϴ�.
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			map[i][j] = 0;
		}
	}
}

// ������ �Է��� �޽��ϴ�.
void ReceiveInput()
{
	cin >> N >> M;
	
	// CCTV ���ڸ� ���� �ӽ�
	int temp = 0;
	int	temp2 = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp2;

			if (temp2 == 6) {
				map[i][j] = -1;
			}
			else {
				map[i][j] = temp2;
			}
			

			if (temp2 > 0 && temp2 != 6) {
				CCTV[temp].type = temp2;
				CCTV[temp].x = i;
				CCTV[temp].y = j;
				temp++;
			}

		}
	}
}

// CCTV�� Ÿ�Ը��� �� �� �ִ� ����� ������ �Լ��Դϴ�.
void MarkingMap(int dir, int CCTVNumber, int check)
{
	switch (CCTV[CCTVNumber].type) {
		case 1:	
			switch (dir) {
				case 0: // 1�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y + 1 ; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 1: // 1�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 2: // 1�� Ÿ�� ī�޶� �Ʒ� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 3: // 1�� Ÿ�� ī�޶� �� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
			}
	 	    break;

		case 2:
			switch (dir) {
				case 0: // 2�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
						// 2�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 1: // 2�� Ÿ�� ī�޶� �Ʒ� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
						// 2�� Ÿ�� ī�޶� �� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
				case 2:
					break;
				case 3:
					break;
			}
			break;

		case 3:
			switch (dir) {
				case 0: // 3�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}

					// 3�� Ÿ�� ī�޶� �� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 1: // 3�� Ÿ�� ī�޶� �� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					// 3�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 2: // 3�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					// 3�� Ÿ�� ī�޶� �Ʒ� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;

				case 3: // 3�� Ÿ�� ī�޶� �Ʒ� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					// 3�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					break;
			}
			break;

		case 4:
			switch (dir) {
				case 0: 
					// 4�� Ÿ�� ī�޶� �� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}

					// 4�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					// 4�� Ÿ�� ī�޶� �Ʒ� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
				case 1: // 4�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}

					// 4�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					// 4�� Ÿ�� ī�޶� �Ʒ� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
				case 2: // 4�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}

					// 4�� Ÿ�� ī�޶� �� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}

					// 4�� Ÿ�� ī�޶� �Ʒ� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
				case 3: // 4�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}

					// 4�� Ÿ�� ī�޶� �� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}

					// 4�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
				break;
			}
			break;

		case 5:
			switch (dir){
				case 0: // 5�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y + 1; i < M; i++) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}

					// 5�� Ÿ�� ī�޶� �� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x - 1; i >= 0; i--) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}

					// 5�� Ÿ�� ī�޶� ���� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].y - 1; i >= 0; i--) {
						if (map[CCTV[CCTVNumber].x][i] == -1) break;
						map[CCTV[CCTVNumber].x][i] += CCTV[CCTVNumber].type * check;
					}
					// 5�� Ÿ�� ī�޶� �Ʒ� ���� �Ǵ� ����
					for (int i = CCTV[CCTVNumber].x + 1; i < N; i++) {
						if (map[i][CCTV[CCTVNumber].y] == -1) break;
						map[i][CCTV[CCTVNumber].y] += CCTV[CCTVNumber].type * check;
					}
					break;
				case 1: 
					break;
				case 2: 
					break;
				case 3: 
					break;
			}
			break;

			break;
	}
}

// CCTV�� �� �� �ִ� ��� ����� ���� Ȯ���մϴ�.
void DFS(int cctvNumber)
{
	// ���� CCTV�� �ִ� ������ �Ѱų� ���� CCTV�� ���ٸ� �� ������ ī��Ʈ �մϴ�.
	if (cctvNumber == 8 || CCTV[cctvNumber].type == -1) {		
		int temp = 0;
		// �簢���븦 ī��Ʈ �մϴ�.
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[j][i] == 0){
					temp++;
				}
			}
		}

		if (temp < MinBlindSpot) {
			MinBlindSpot = temp;
		}
		return;
	}

	// ��� ����� ���� Ȯ��
	for (int i = 0; i < 4; i++) {
		switch (i)
		{
			case 0:
				MarkingMap(i, cctvNumber, 1);
				DFS(cctvNumber + 1);
				MarkingMap(i, cctvNumber, -1);
				break;

			case 1:
				MarkingMap(i, cctvNumber, 1);
				DFS(cctvNumber + 1);
				MarkingMap(i, cctvNumber, -1);
				break;

			case 2:
				MarkingMap(i, cctvNumber, 1);
				DFS(cctvNumber + 1);
				MarkingMap(i, cctvNumber, -1);
				break;
			case 3:
				MarkingMap(i, cctvNumber, 1);
				DFS(cctvNumber + 1);
				MarkingMap(i, cctvNumber, -1);
				break;
		}
	}
}

int main()
{
	Initialization();
	ReceiveInput();
	DFS(0);
	cout << MinBlindSpot;
	// ����׿�
	if (debugBool) DebugPrint();
	return 0;
}