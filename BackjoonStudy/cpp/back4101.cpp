#include <iostream>

using namespace std;

pair<int, int> tempPiar;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	 // cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> tempPiar.first >> tempPiar.second;
		if (tempPiar.first == 0 && tempPiar.second == 0) break;
		else if (tempPiar.first > tempPiar.second) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}

	return 0;
}