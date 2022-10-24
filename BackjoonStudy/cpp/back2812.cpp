//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int N, K;
//char C;
//string Number= "";
//
//
//int inConditionMaxNumberIndex;
//int maxNumber, maxNumberIndex;
//int condition;
//int indexCnt;
//void Initalization()
//{
//	cin >> N >> K;
//	condition = N - K;
//	indexCnt = 0;
//
//	while (N > 0)
//	{
//		cin >> C;
//		Number.push_back(C);
//
//		if (condition > 0)
//		{
//			if (maxNumber < C)
//			{
//				maxNumber = C;
//				maxNumberIndex = indexCnt;
//			}
//			condition--;
//		}
//		indexCnt++;
//		N--;
//	}
//}
//
//int main()
//{
//	Initalization();
//	cout << Number;
//	cout << " maxNumber : " << (char)maxNumber << "  maxNumberIndex : " << maxNumberIndex << "\n";
//	Number = Number.substr(maxNumberIndex);
//	cout << "Number : " << Number << "\n";
//	K = K - maxNumberIndex;
//
//	int temp = 0;
//	int temp2 = 0;
//	while (temp < 10 && K > 0 )
//	{
//		temp2 = Number.find_first_of('0' + temp);
//		cout << "temp : " << temp  << "  temp2 : " << temp2 << "\n";
//		if (temp2 != string::npos)
//		{
//			Number.erase(temp2,1);
//			K--;
//		}
//	
//		temp++;
//	}
//
//	cout << "result : " << Number;
//
//	char a = '9';
//	int a2 = 9;
//	char a3 = '0' + a2;
//	int x = Number.find_first_of(a);
//	if (x != string::npos)
//	{
//		Number.erase(x , 1);
//	}
//	cout << "\n" << x << " a2 : " << a2 << " a3  : " << a3 << "\n";
//	cout << "result : " << Number;
//}