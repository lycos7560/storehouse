#include <iostream>
#include <map>

using namespace std;

multimap<int, int> myMap;
multimap<int, int> myMap2;

int arr[3];

// multimap�� Ư���� �̿��� ����

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> arr[0];
	for (int i = 0; i < arr[0]; i++) {
		cin >> arr[1] >> arr[2];
		myMap.insert(make_pair(arr[1],arr[2]));
	}

	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		myMap2.insert(make_pair(it->second, it->first));
	}

	for (auto it = myMap2.begin(); it != myMap2.end(); it++) {
		cout << it->second << " " << it->first << "\n";
	}

	return 0;
}