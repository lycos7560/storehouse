//#include <iostream>
//#include <string>
//#include <stack>
//
//using namespace std;
//
//stack<char> myStack;
//int n, k;
//char c;
//string number = "";
//string result = "";
//
//void Initalization()
//{
//	cin >> n >> k;
//
//	int temp = n;
//	while (temp > 0)
//	{
//		cin >> c;
//		number.push_back(c);
//		temp--;
//	}
//}
//
//
//int main()
//{
//	// 입력을 초기화 해주는 함수
//	Initalization();
//	
//	// 처음 시작을 위해 하나 넣어준다.
//	myStack.push(number[0]);
//
//	for (int i = 1; i < number.length(); i++)
//	{
//		// 제거 가능한 수가 0 이면 스택에 넣고 넘어간다. 
//		if (k == 0)
//		{
//			myStack.push(number[i]);
//			continue;
//		}
//		
//		// 만약 스택의 숫자보다 비교 숫자보다 크다면 
//		// 스택의 숫자를 제거하고 다시 스텍의 수와 비교
//		// 스텍이 비거나 비교숫자보다 크거나 같으면 
//		// 비교 숫자를 스택에 넣어준다.
//		if (myStack.top() < number[i])
//		{
//
//			while (myStack.top() < number[i] && !myStack.empty() && k > 0)
//			{
//				myStack.pop();
//				k--;
//				if (myStack.empty())
//				{
//					break;
//				}
//			}
//
//			myStack.push(number[i]);
//		}
//		else if (myStack.top() >= number[i])
//		{ 
//			// 만약 스택의 숫자보다 비교 숫자보다 크다면 
//		    // 숫자를 스택에 넣어준다.
//			myStack.push(number[i]);
//			continue;
//		}
//	}
//
//	// 모든 숫자를 전부다 비교해도 제거 가능한 숫자가 남으면
//	// 그 수만큼 스택에서 제거한다.
//	while (k > 0)
//	{
//		myStack.pop();
//		k--;
//	}
//
//	while (!myStack.empty())
//	{
//		result.push_back(myStack.top());
//		myStack.pop();
//	}
//
//	// 반대로 출력되므로 뒤집어준다.
//	string resultReverse(result.rbegin(), result.rend());
//	cout << resultReverse;
//}
//
///*
//10 4
//7898111101
//
//981111
//
//10 4
//7898111102
//
//981112
//
//
//10 5
//9993333932
//
//99993
//
//
//10 5
//9993333912
//답 : 99992
//
//---
//
//5 3
//98291
//답 : 99
//
//6 3
//988291
//답 : 991
//
//---
//
//10 4
//9876543333
//답 : 987654
//
//10 4
//9876334533
//답 : 987653
//
//4 2
//1924
////answer : 94
//
//7 3
//1231234
////answer : 3234
//
//10 4
//4177252841
////answer : 775841
//
//6 2
//391123
////answer : 9123
//
//6 2
//436436
////answer: 6436
//
//7 3
//7654321
////answer: 7654
//
//6 2
//362514
////answer : 6514
//
//2 1
//19
////answer : 9
//
//
//4 2
//1324
//
//34
//
//
//4 1
//8849
//
//889
//
//
//8 2
//15446321
//
//546321
//
//
//7 5
//9929191
//
//99
//
//
//5 3
//99291
//
//99
//
//
//
//6 3
//773671
//
//777
//
//
//
//4 2
//9879
//
//99
//
//
//
//10 3
//2222211113
//
//2222213
//
//
//
//10 3
//1111122223
//
//1122223
//
//
//9 2
//999991111
//
//9999911
//
//*/