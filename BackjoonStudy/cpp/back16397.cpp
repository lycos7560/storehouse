//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N, T, G;
//// N: LED�� ����, T: ��ư�� ���� �� �ִ� Ƚ��, G: ��ǥ ����
//int result = 0;
//// ���
//bool failConditionCheck = true;
//// ������ ��� ��� true;
//
//queue<int> myQ;
////BFS���� ����� queue
//
//#define MAX 100000
//
//int check[MAX];
//
//// ��ư A ����� �Լ�
//int BtnA(int number)
//{
//	number += 1;
//	return number;
//}
//
//// ��ư B ����� �Լ�
//int BtnB(int number)
//{
//	number *= 2;
//
//	int i = 10000;
//	while (i >= 1)
//	{
//		if (number / i != 0)
//		{
//			number -= i;
//			break;
//		}
//		i = i / 10;
//	}
//
//	return number;
//}
//
//// �ʱ�ȭ �Լ�
//void Initialization()
//{
//	cin >> N >> T >> G;
//	
//	//�迭 �ʱ�ȭ
//	for (int i = 0; i < MAX; i++)
//	{
//		check[i] = 0;
//	}
//}
//
//// BFS ����� �Լ�
//void BFS(int N)
//{
//	myQ.push(N);
//	while (!myQ.empty())
//	{
//		int a = myQ.front();
//		myQ.pop();
//
//		// �湮�� ���� �ְų� ����Ƚ���� T�� �Ѿ�� �Ѿ
//		if (check[a] > T)
//		{
//			continue;
//		}
//
//		if (a == G)
//		{   
//			// LED�� G�� ���� ���� ���
//			failConditionCheck = false;
//		}
//
//		// ��ư A�� B�� ������ ��츦 Q�� ����
//		for (int i = 0; i < 2; i++)
//		{
//			int temp = 0;
//			switch (i)
//			{
//				case 0:
//					if (a >= 99999)
//					{
//						break;
//					}
//					temp = BtnA(a);
//					if (check[temp] == 0)
//					{
//						myQ.push(temp);
//						check[temp] = check[a] + 1;
//					}
//					break;
//
//				case 1:
//					if (a > 49999)
//					{
//						break;
//					}
//					temp = BtnB(a);
//					if (check[temp] == 0)
//					{
//						myQ.push(temp);
//						check[temp] = check[a] + 1;
//					}
//					break;
//			}
//		}
//	}
//}
//
//int main()
//{
//	Initialization();
//	BFS(N);
//
//	if (failConditionCheck)
//	{
//		cout << "ANG";
//	}
//	else
//	{
//		result = check[G];
//		cout << result;
//	}
//
//	return 0;
//}