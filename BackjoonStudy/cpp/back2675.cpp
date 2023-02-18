#include <iostream>
#include <list>

using namespace std;

list<pair<int, string>> pairList;
list<pair<int, string>>::iterator it;
pair<int, string> myPair;

int main()
{
	int N = 0;

	string temp = "";

	cin >> N;

	while (N-- > 0) { 
		// myPair.first : �ݺ� Ƚ��, myPair.second : ���ڿ�
		cin >> myPair.first >> myPair.second; 
		pairList.push_back(myPair); // ������ �߰�
	}
	
	// ����Ʈ�� ��ȸ
	for (it = pairList.begin(); it != pairList.end(); it++) {
		
		//���ڿ� �ʱ�ȭ
		temp = "";

		// ���ڿ��� ���̸�ŭ �ݺ� (��� ���ڿ��� R��ŭ �ݺ���)
		for (int j = 0; j < it->second.length(); j++) { 

			// j �ε��� ���ڸ� R�� �ݺ�(it->first)
			for (int i = 0; i < it->first; i++) {

				// temp ���ڿ��� �߰�
				temp.push_back(it->second[j]);
			}
		}
		cout << temp << "\n";
	}

	return 0;

}