#include <iostream>
#include <algorithm>

using namespace std;

string str;

int arr[3];

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 3; i++) cin >> arr[i];

	sort(arr, arr + 3);

	for (int i = 0; i < 3; i++) cout << arr[i] << " ";

	return 0;
}