//#include <iostream>
//#include <set>
//
//using namespace std;
//
//set<int> myset;
//set<int> :: iterator iter;
//
//int temp = 0;
//int lenghtTape = 0;
//int result = 0;
//
//// �ʱ�ȭ �Լ�
//void Intialization()
//{
//	int N = 0;
//	cin >> N >> lenghtTape;
//	while (N > 0)
//	{
//		cin >> temp;
//		myset.insert(temp);
//		N--;
//	}
//}
//
//int main()
//{
//	// ������ �ʱ�ȭ�Ѵ�.
//	Intialization();
//
//	// �������� Ŀ���� �� �ִ� ����ġ�� ǥ��
//	int pos = 0;
//
//	// �¿� �־ ���ĵ� ���� ���� ��ġ�� ��ȸ�Ѵ�.
//	for (iter = myset.begin(); iter != myset.end(); iter++)
//	{
//		// ���� ���� ��ġ�� �������� Ŀ�� ������ ������� �Ѿ��.
//		if (*iter <= pos)
//		{
//			continue;
//		}
//
//		// �������� Ŀ�� ������ ��ġ�� �ƴϹǷ� �������� �߰��ϰ� Ŀ�� ������ �Ѱ��ش�.
//		pos = *iter + (lenghtTape - 1);
//		result++;
//	}
//
//
//	cout << result;
//	return 0;
//}