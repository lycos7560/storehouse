#include <iostream>
#include <cmath>

using namespace std;

int N, r, c, cnt, result;

// (����, ���� x ��ǥ , ���� y ��ǥ)
void DivideAndConquer(int w, int x, int y)
{
	if (w == 1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++){
				if (x + i == r && y + j == c ) result = cnt;
				cnt++;
			}
		}
		return;
	}
	
	// R, C �� ��ġ�� �� 4�и����� ����� 
	// �ش� ��ġ�� ���ٸ� ����Լ��� ���������ʰ� ������� �ð� ����
	if (result == 0) { // ����� �������� ���̻� �������� �ʴ´�.
		if (x + pow(2, w - 1) > r && y + pow(2, w - 1) > c) DivideAndConquer(w - 1, x, y); // 2
		else  cnt += pow(pow(2, w - 1), 2);

		if (x + pow(2, w - 1) > r && y + pow(2, w - 1) <= c) DivideAndConquer(w - 1, x, y + pow(2, w - 1)); // 1
		else  cnt += pow(pow(2, w - 1), 2);

		if (x + pow(2, w - 1) <= r && y + pow(2, w - 1) > c) DivideAndConquer(w - 1, x + pow(2, w - 1), y); // 3
		else  cnt += pow(pow(2, w - 1), 2);

		if (x + pow(2, w - 1) <= r && y + pow(2, w - 1) <= c) DivideAndConquer(w - 1, x + pow(2, w - 1), y + pow(2, w - 1)); // 4
		else  cnt += pow(pow(2, w - 1), 2);

	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cnt = 0;
	result = 0;

	cin >> N >> r >> c;
	
	// ���� ����
	DivideAndConquer(N, 0, 0);

	cout << result;

	return 0;
}
