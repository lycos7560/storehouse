#include <iostream>
#include <list>

using namespace std;

string answer[2] = { "yes", "no" };

list<string> answerList;

int temp;

int main()
{
	string str = "";
	
	while (true) { // ��� �ݺ�
		
		cin >> str;
		
		if (str == "0") break; // 0�� �Է¹����� stop
		temp = 0;
		
		for (int i = 0; i < str.length()/2; i++) { // Ȧ���� ��� ����� �ǹ̰� ����
			
			if (str[i] != str[str.length() -1 - i]) { temp = 1; }

		}

		answerList.push_back(answer[temp]); // ����Ʈ�� ���� �ִ´�
	}

	// ����Ʈ�� ��ȸ�ϸ鼭 ���
	for (auto it = answerList.begin(); it != answerList.end(); it++) {
		cout << *it << "\n";
	}

	return 0;
}