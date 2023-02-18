#include <iostream>

using namespace std;

int N, S, result = 0;

string str;

int main()
{
	cin >> N >> S >>  str;

	for (int i = 0; i < str.length(); i++) {

		// ������ O �̶�� �Ѿ��.
		if (str[i] == 'O') continue;

		// i + 1�� i + 2�� ���� Ȯ���Ѵ�.(P1�� �����ϴ� �� Ȯ��)
		if (str[i + 1] == 'O' && str[i + 2] == 'I') {

			// cnt�� N�� ���� �������ٸ� PN �� �ϳ� �����Ѵٴ� �ǹ�
			int cnt = 0;

			// ������ �����ϸ� �ݺ�
			while (str[i] == 'I' && str[i + 1] == 'O') {
				// �ε����� ��ĭ �̵�
				i += 2;

				cnt++;

				if (str[i] == 'I' && cnt == N) {
					cnt--; // �ڿ� 'O' �ϳ� ���� ex) P1 => IOIO Ȯ���� -�� ���ش�.
					result++;
				}
			}
		}
	}
	
	cout << result << "\n";

	return 0;
}