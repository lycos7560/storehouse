#include <iostream>
#include <list>

using namespace std;

list<int> intList;

int N, X, temp;

int main()
{

	cin >> N >> X;
	
	while (N-- > 0) {
		cin >> temp;
		if (X > temp) {
			// X ���� �Է¹��� ���� �۴ٸ�
			// ����Ʈ�� �ִ´�.
			intList.push_back(temp);
		}
	}

	// ����Ʈ�� ��ȸ�ϸ� ����� ����Ѵ�.
	for (auto it = intList.begin(); it != intList.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}