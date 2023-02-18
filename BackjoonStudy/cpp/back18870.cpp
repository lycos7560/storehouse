#include <iostream>
#include <map>

using namespace std;

int arrN[1000001];
int number[1000000];

map<int, int> myMap;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> arrN[0];

	for (int i = 1; i <= arrN[0]; i++) cin >> arrN[i];

	// map���� �������� ���� 
	for (int i = 1; i <= arrN[0]; i++) 
		myMap.insert(make_pair(arrN[i], 0)); 

	int cnt = 0;
	for (auto it = myMap.begin(); it != myMap.end(); it++) 
		it->second = cnt++;

	for (int i = 1; i <= arrN[0]; i++) 
		cout << myMap.find(arrN[i])->second << " ";

	return 0;
}
