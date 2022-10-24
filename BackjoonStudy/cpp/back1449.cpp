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
//// 초기화 함수
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
//	// 조건을 초기화한다.
//	Intialization();
//
//	// 테이프가 커버할 수 있는 끝위치를 표시
//	int pos = 0;
//
//	// 셋에 넣어서 정렬된 물이 새는 위치를 순회한다.
//	for (iter = myset.begin(); iter != myset.end(); iter++)
//	{
//		// 만약 새는 위치가 테이프가 커버 가능한 범위라면 넘어간다.
//		if (*iter <= pos)
//		{
//			continue;
//		}
//
//		// 테이프가 커버 가능한 위치가 아니므로 테이프를 추가하고 커버 범위를 넘겨준다.
//		pos = *iter + (lenghtTape - 1);
//		result++;
//	}
//
//
//	cout << result;
//	return 0;
//}