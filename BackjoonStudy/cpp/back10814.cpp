#include <iostream>
#include <map>

using namespace std;

string name[100000];

multimap<int, int> myMap;

int N, temp, temp2 = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp >> name[i];
		// string[��ϼ���] �迭�� �̸��� �����صд�.
		myMap.insert(make_pair(temp, i));
		// ��Ƽ�ʿ� (����, ��ϼ���) �����Ѵ�.
		// ���̰� ���ٸ� ��ϼ����� ���� ���ĵȴ�. (��������)
	}

	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		// �̸��迭[��ϼ�] = ������ ���´�.
		cout << it->first << " " << name[it->second] << "\n";
	}

	return 0;
}
