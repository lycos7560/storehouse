#include <iostream>

using namespace std;

int t, n, res, temp;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;
		res = 0;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			res += temp;
		}
		cout << res << "\n";
	}

	return 0;
}