#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	string str;

	for (int i = 0; i < N; i++) str.push_back('*');
	while (N-- > 0) {
		for (int i = N; i >= 0; i--)
			cout << str[i];

		cout << "\n";
	}

	return 0;
}