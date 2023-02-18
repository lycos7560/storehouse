#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

int N, M;

string strOne, strTwo;

unordered_map<string, string> uMap;

list<string> myList;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// unordered_map�� ����Ʈ�� ��й�ȣ�� ����
	for (int i = 0; i < N; i++) {
		cin >> strOne >> strTwo;
		uMap.insert(make_pair(strOne, strTwo));
	}

	// ��й�ȣ�� �ʿ��� ����Ʈ�� ����Ʈ�� ����
	for (int i = 0; i < M; i++) {
		cin >> strOne;
		myList.push_back(strOne);
	}

	// ����Ʈ�� key�� ��(��й�ȣ)�� �˻�
	for (auto it = myList.begin(); it != myList.end(); it++) {
		strOne = *it;
		cout << uMap.find(strOne)->second << "\n";
	}

	return 0;
}