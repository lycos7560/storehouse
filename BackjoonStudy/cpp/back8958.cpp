#include <iostream>
#include <list>
using namespace std;

list<string> stringList;
list<string>::iterator it;

string temp;
int N, result;

int main()
{	
	// �׽�Ʈ ���̽��� ���� N�� �ֽ��ϴ�.
	cin >> N;
	// �׽�Ʈ ���̽���ŭ ���ڿ��� �Է¹ް�
	// ����Ʈ�� �ֽ��ϴ�.
	while (N-- >0) {
		cin >> temp;
		stringList.push_back(temp);
	}

	// �Է¹��� ���ڿ� ����Ʈ�� ��ȸ 
	for (it = stringList.begin(); it != stringList.end(); it++) {

		temp = *it;

		N = 0; // O ���� ī��Ʈ
		result = 0; // ������ ����

		// ���� temp[i] == 'O' �̶�� N�� ī��Ʈ�� �ϳ� �÷��ְ� (���ӵ� O�� ���� ���� )
		// �ƴ϶�� N�� O���� ������ش�.
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == 'O') { N++; } 
			else { N = 0; }
			result += N;
		}

		// �ش� ���ڿ��� �ݺ��� ������ ����� ���

		cout << result << "\n";

	}

	return 0;
}