//#include <iostream>
//#include <set>
//
//using namespace std;
//
//multiset<int> myMultiset;
//multiset<int> ::iterator iter;
//
//int temp = 0;
//int temp2 = 0;
//int result = 0;
//int result2 = 0;
//
//// ������ �ʱ�ȭ
//void Initialization()
//{
//	cin >> temp;
//	while (temp > 0)
//	{
//		cin >> temp2;
//		myMultiset.insert(temp2);
//		temp--;
//	}
//}
//
//int main()
//{
//	Initialization();
//
//	temp = 0;
//	temp2 = 0;
//
//	// ������ �����Ҷ����� �ݺ�
//	while (true)
//	{
//		iter = myMultiset.begin();
//		temp = *iter;
//		myMultiset.erase(iter);
//		result = temp;
//		
//		// ���� ��Ƽ���� ����ִٸ� ī���� ������ �ϳ�
//		// ���� ���� �ʿ䰡 ����
//		if (myMultiset.empty())
//		{
//			break;
//		}
//
//		iter = myMultiset.begin();
//		temp2 = *iter;
//		myMultiset.erase(iter);
//		result = temp + temp2;
//		myMultiset.insert(result);
//		result2 += result;
//	}
//
//	cout << result2;
//
//	return 0;
//}