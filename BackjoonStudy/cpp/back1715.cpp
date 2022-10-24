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
//// 설정을 초기화
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
//	// 조건을 만족할때까지 반복
//	while (true)
//	{
//		iter = myMultiset.begin();
//		temp = *iter;
//		myMultiset.erase(iter);
//		result = temp;
//		
//		// 만약 멀티셋이 비어있다면 카드의 묶음이 하나
//		// 더는 비교할 필요가 없음
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