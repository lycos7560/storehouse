#include <iostream>
#include <cmath>

using namespace std;

string str, tempStr;

int result = 0;
bool check = false;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	// �ѹ��̶� - �� ���´ٸ� ���� ������ ���� ���ش�.
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 45) { // '-' = 45
			result += atoi(tempStr.c_str()) * ( pow(-1, check));
			check = true;
			tempStr = "";
		}
		else if (str[i] == 43) { // '+' = 43
			result += atoi(tempStr.c_str()) * (pow(-1, check));
			tempStr = "";
		}
		else tempStr.push_back(str[i]);
	}

	// ������ ���� �ذ�
	result += atoi(tempStr.c_str()) * (pow(-1, check));

	cout << result;

	return 0;
}