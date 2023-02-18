#include <iostream>

using namespace std;

// ������ 2^7 = 128
constexpr int MAX = 129;

int N;

// 0 - white, 1 - bule
int result[2];

int map[MAX][MAX];

// (����, ���� x ��ǥ , ���� y ��ǥ)
void DivideAndConquer(int w, int x, int y)
{
	if (w == 1) { 
		// ���̰� 1�̸� �ش� ������ ���� ������
		result[map[x][y]]++;
		return;
	} 

	int check = 0;

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			 check += map[x + i][y + j];
			 // ������ �� ���ؼ� 0 �̸� �Ͼ�� ������
			 // W * W �̸� �Ķ��� ������
		}
	}

	if (check == 0) {
		result[0]++; // �Ͼ�� ������ �߰�
	}
	else if (check == w * w) {
		result[1]++; // �Ķ��� ������ �߰�
	}
	else { // ���� ����
		DivideAndConquer(w / 2, x , y );
		DivideAndConquer(w / 2, x + w / 2, y );
		DivideAndConquer(w / 2, x        , y  + w / 2);
		DivideAndConquer(w / 2, x + w / 2, y  + w / 2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	// ���� ����
	DivideAndConquer(N, 1, 1);

	// ��� ���
	cout << result[0] << "\n" << result[1];

	return 0;
}
