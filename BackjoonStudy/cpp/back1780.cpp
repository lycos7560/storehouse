#include <iostream>
#include <cmath>

using namespace std;

constexpr int MAX = 2187;

int map[MAX][MAX];

int N;

// 0 = 0 / 1 = 1 / -1 = 2
int result[3];

void ConquestDivison(int x, int y, int w)
{
	// ������ ���̰� 1(3^0) �̶�� �ش� ������ ī��Ʈ�� �������� �ݴϴ�.
	if (w == 0) { 
		if (map[x][y] == -1) result[2]++;
		else result[map[x][y]]++;
		return;
	}

	int number = map[x][y];
	int temp = pow(3, w);
	bool check = true;
	for (int i = 0; i < temp; i++) {
		for (int j = 0; j < temp; j++) {
			// ��� �κ��� ���� ������ üũ�մϴ�.
			// �ٸ��ٸ� ���������� ��ŷ���ݴϴ�.
			if (number == map[x + i][y + j]) { continue; }
			else {
				check = false;
				break;
			}
		}
		if (!check) break;
	}

	if (check) { // ��� �κ��� ���ٸ� �ذ� ������ ī��Ʈ�� �÷��ݴϴ�.
		if (number == -1) result[2]++;
		else result[map[x][y]]++;
		return;
	}
	
	int temp2 = pow(3, w - 1);

	// ���� ���� 9���
	ConquestDivison(x              , y              , w - 1);
	ConquestDivison(x              , y + temp2      , w - 1);
	ConquestDivison(x              , y + 2 * (temp2), w - 1);

	ConquestDivison(x + temp2	   , y				, w - 1);
	ConquestDivison(x + temp2	   , y + temp2		, w - 1);
	ConquestDivison(x + temp2	   , y + 2 * (temp2), w - 1);

	ConquestDivison(x + 2 * (temp2), y	            , w - 1);
	ConquestDivison(x + 2 * (temp2), y + temp2	    , w - 1);
	ConquestDivison(x + 2 * (temp2), y + 2 * (temp2), w - 1);
}


int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// ������ �Է¹޽��ϴ�.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// N�� 3�� ������� Ȯ���մϴ�.
	int k = 0;
	int temp = N;
	while (temp != 1) {
		temp /= 3;
		k++;
	}
	
	ConquestDivison(0, 0, k);

	cout << result[2] << "\n" << result[0] << "\n" << result[1];

	return 0;
}