//#include <iostream>
//#include <string>
//#include <list>
//#include <cmath>
//
//using namespace std;
//
////알파벳의 대문자의 범위는 90까지
//#define max 91
//
//int n = 0;
//int result = 0;
//int alphabet[max];
//list<int> myalphabetlist;
//
//int main()
//{
//	// 초기화
//	for (int i = 0; i < max; i++)
//	{
//		alphabet[i] = 0;
//	}
//
//	// 단어의 수를 입력 받음
//	cin >> n;
//
//	while (n > 0)
//	{
//		// string 값으로 입력을 받음
//		string tempstr = "";
//		cin >> tempstr;
//
//		// string 값의 인덱스에 따른 가치를 더해준다.
//		// ex] 3 abc bbb a = 101, b = 121, c = 1
//		for (int i = tempstr.length() - 1; i >= 0; i--)
//		{
//			alphabet[(int)tempstr[i]] += pow(10, tempstr.length() - i - 1);
//		}
//
//		// 단어를 받은 만큼 n을 감소
//		n--;
//	}
//
//	for (int i = 0; i < max; i++)
//	{
//		// 가치가 입력된 값들을 리스트에 넣음(정렬을 위함)
//		if (alphabet[i] != 0)
//		{
//			myalphabetlist.push_back(alphabet[i]);
//		}
//	}
//
//	// 내림차순으로 정렬 
//	myalphabetlist.sort(greater<int>());
//
//	int value = 9;
//	int result = 0;
//	// 가치가 높은 알파벳 부터 높은 가치를 곱해줌
//	for (int i : myalphabetlist)
//	{
//		result += value * i;
//		value--;
//	}
//
//	// 결과값 출력
//	cout << result;
//	return 0;
//}