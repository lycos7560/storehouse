#include <iostream>

using namespace std;

int N;

string str[51];

int main()
{

	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cin >> str[0];

	for (int i = 1; i < N; i++) {

		cin >> str[i];

		for (int j = 0; j < str[i].length(); j++) {

			if (str[0][j] == str[i][j]) continue;
			else str[0][j] = '?';

		}
	}

	cout << str[0];

}