#include <iostream>
#include <string>

using namespace std;

string str;

int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 8; i++) {

		getline(cin, str);

		if (i % 2 == 0) {
			for (int j = 0; j < str.length(); j++) 
				if (j % 2 == 0 && str[j] == 'F') cnt++;
			}
		else {
			for (int j = 0; j < str.length(); j++) 
				if (j % 2 != 0 && str[j] == 'F') cnt++;	
		}
	}

	cout << cnt;

	return 0;
}