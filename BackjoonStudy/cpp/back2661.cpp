#include <iostream>
#include <string>

using namespace std;

int N;
string number;

void DFS(char ch, int cnt)
{
	// ���� ���� ���ǿ� �����ϴ� ���ڰ� ��
	if (cnt - 1 == N) { 
		cout << number; 
		exit(0);
	}
	
	number += ch;
	
	for (int i = 1; i <= cnt/2; i++)
	{

		// ���ڿ� �ڸ��� => ���ڿ�.substr(���� ��ġ, ����)
		string a = number.substr(cnt - i, i);
		string b = number.substr(cnt - i * 2, i);

		if (a == b){ 
			// ���� �����̸� ����� ����
			number.erase(cnt - 1);
			return;
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		DFS(i + '0', cnt + 1);
	}

	// cnt - 1 �ڸ��� �������� ���� ���
	number.erase(cnt - 1);
}

int main()
{
	cin >> N;
	for (int i = 1; i <= 3; i++)
	{
		// '0' ���� i ��ŭ ���ϸ� i
		DFS(i + '0', 1);
	}

	return 0;
}