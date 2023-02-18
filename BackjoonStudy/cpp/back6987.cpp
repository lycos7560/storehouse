#include <iostream>

using namespace std;

// ������ ���� ����� �ֱ�
int predictedArr[4][6][3];

// ������ ���� �� 15���
int gameArr1[15] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
int gameArr2[15] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};

// Win Draw Lose ���
int scoreWDL[6][3];

// ����� �����ؼ� �������� ���
int result[4];


void Initalization()
{
	//��� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		result[i] = 0;
	}

	// ���� ���ھ �޽��ϴ�.
	for (int n = 0; n < 4; n++)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> predictedArr[n][i][j];
			}
		}
	}
}

void CheckScoreRecursive(int gameCnt)
{
	// ���� ��� ��Ⱑ �����ٸ�
	if (gameCnt == 15) {
		//��
		for (int n = 0; n < 4; n++) {

			bool check = true;

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					if (predictedArr[n][i][j] != scoreWDL[i][j]) {
						check = false;
						break;
					}
				}

				// ���� ����� �����ϸ� �극��ũ
				if (!check) break;
			}

			// �ش� ����� �����ϸ� ����
			if (check) {
				result[n] = 1;
			}
		}

		return;
	}

	// ������ Arr1
	// �¸����� ���
	scoreWDL[gameArr1[gameCnt]][0]++;
	scoreWDL[gameArr2[gameCnt]][2]++;
	CheckScoreRecursive(gameCnt + 1);
	scoreWDL[gameArr1[gameCnt]][0]--;
	scoreWDL[gameArr2[gameCnt]][2]--;

	// ���º��� ���
	scoreWDL[gameArr1[gameCnt]][1]++;
	scoreWDL[gameArr2[gameCnt]][1]++;
	CheckScoreRecursive(gameCnt + 1);
	scoreWDL[gameArr1[gameCnt]][1]--;
	scoreWDL[gameArr2[gameCnt]][1]--;

	// �й��� ���
	scoreWDL[gameArr1[gameCnt]][2]++;
	scoreWDL[gameArr2[gameCnt]][0]++;
	CheckScoreRecursive(gameCnt + 1);
	scoreWDL[gameArr1[gameCnt]][2]--;
	scoreWDL[gameArr2[gameCnt]][0]--;
}

int main()
{
	Initalization();

	// DFS�� ���� 
	CheckScoreRecursive(0);

	// ��� ���
	for (int i = 0; i < 4; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}