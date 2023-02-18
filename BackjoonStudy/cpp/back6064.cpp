#include <iostream>

using namespace std;

int T, N, M, x, y, result, temp;

// ��Ŭ���� ȣ����(�ִ� ����� ���ϱ�)
int gcd(int a, int b) 
{
	return b ? gcd(b, a % b) : a;
}

// �ּ� ����� ���ϱ�
int LCM(int a , int b) {
	return a * b / gcd(a, b);
}

int main()
{
	cin >> T;

	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	while (T-- > 0) {

		cin >> N >> M >> x >> y;

		result = -1;

		for (int i = x; i <= LCM(N, M); i += N) {

			if (i % M == 0) temp = M;
			else temp = i % M;

			if (temp == y) {
				result = i;
				break;
			}
		}

		if (result > 0) cout << result << "\n";
		else cout << -1 << "\n";
	}

	return 0;
}