#include <iostream>
#include <map>

using namespace std;

map<string, int> myMap;

multimap<int, string> mMap;

string str;

int n;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	// map�� �־ �ߺ��� �ܾ �����ϰ�
	// ���ĺ� ������ ���� �մϴ�. (map�� ����)
	// key = string, value = int 
	for (int i = 0; i < n; i++) {
		cin >> str;
		myMap.insert(make_pair(str, str.length()));
	}

	// multimap�� �־� ���ڰ� ������ ���� ������� �Էµ˴ϴ�.
	// key = int (multimap�� �ߺ� ���), value = string
	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		mMap.insert(make_pair(it->second, it->first));
	}

	for (auto it = mMap.begin(); it != mMap.end(); it++) {
		cout << it->second << "\n";
	}
	return 0;
}