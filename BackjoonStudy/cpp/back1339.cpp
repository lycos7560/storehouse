//#include <iostream>
//#include <string>
//#include <list>
//#include <cmath>
//
//using namespace std;
//
////���ĺ��� �빮���� ������ 90����
//#define max 91
//
//int n = 0;
//int result = 0;
//int alphabet[max];
//list<int> myalphabetlist;
//
//int main()
//{
//	// �ʱ�ȭ
//	for (int i = 0; i < max; i++)
//	{
//		alphabet[i] = 0;
//	}
//
//	// �ܾ��� ���� �Է� ����
//	cin >> n;
//
//	while (n > 0)
//	{
//		// string ������ �Է��� ����
//		string tempstr = "";
//		cin >> tempstr;
//
//		// string ���� �ε����� ���� ��ġ�� �����ش�.
//		// ex] 3 abc bbb a = 101, b = 121, c = 1
//		for (int i = tempstr.length() - 1; i >= 0; i--)
//		{
//			alphabet[(int)tempstr[i]] += pow(10, tempstr.length() - i - 1);
//		}
//
//		// �ܾ ���� ��ŭ n�� ����
//		n--;
//	}
//
//	for (int i = 0; i < max; i++)
//	{
//		// ��ġ�� �Էµ� ������ ����Ʈ�� ����(������ ����)
//		if (alphabet[i] != 0)
//		{
//			myalphabetlist.push_back(alphabet[i]);
//		}
//	}
//
//	// ������������ ���� 
//	myalphabetlist.sort(greater<int>());
//
//	int value = 9;
//	int result = 0;
//	// ��ġ�� ���� ���ĺ� ���� ���� ��ġ�� ������
//	for (int i : myalphabetlist)
//	{
//		result += value * i;
//		value--;
//	}
//
//	// ����� ���
//	cout << result;
//	return 0;
//}