#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N =0 , sum = 0;
	string str = "";
	
	cin >> N;

	cin.ignore(); 
	// �Է� ���ۿ� �ִ� ��� ������ �����ؼ� ������.

	getline(cin, str);
	// 2��° ���� string���� �޾��ش�.

	// �ε��� ��ȸ
	for (int i = 0; i < N; i++) {
		sum += str[i] - '0'; // char => int
	}

	cout << sum;

	return 0;
}