#include <iostream>
#include <list>

using namespace std;

list <pair<int, int>> tempList;
list <pair<int, int>>::iterator it;

pair<int, int> temp;

int main()
{
	while (true) {

		// pair<int, int> �Է� ���� �ִ´�.
		cin >> temp.first >> temp.second;

		// �Է� ���������� 0 0 �� ������ ���� üũ�ϰ�
		// ����Ʈ���� ���� �ʴ´�.
		if (temp.first == 0 && temp.second == 0) { break;}

		//����Ʈ�� �Է��� �ִ´�.
		tempList.push_back(temp);
	}
	
	// ����Ʈ�� ��ȸ�ϸ鼭 ���Ѱ��� ����Ѵ�.
	for (it = tempList.begin(); it != tempList.end(); it++) 
		cout << it->first + it->second << "\n";

	return 0;
}