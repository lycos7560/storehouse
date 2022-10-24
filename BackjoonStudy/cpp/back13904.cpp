//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//// ������ �������� �������� ������������ ����
//priority_queue<pair<int, int>> PriorityQueue_DeadLine_Value;
//
//// ������ ������ �������� �������� ����
//priority_queue<int> PriorityQueue_Value;
//
//int N, temp, temp2, taskDeadlineMax, result;
//pair<int, int> myPair;
//
//// �Է� �ʱ�ȭ�� �޴� �κ�
//void Initailization()
//{
//	cin >> N;
//	while (N > 0)
//	{
//		cin >> temp >> temp2;
//
//		PriorityQueue_DeadLine_Value.push(make_pair(temp, temp2));
//
//		// ���� �߿��� ���� ���� ������ ���� ã�´�.
//		if (taskDeadlineMax < temp){ taskDeadlineMax = temp; }
//
//		N--;
//	}
//}
//
//void Recursive(int cuurentDay)
//{
//	// ���� ���� ���� 0 �̸� �����ؼ� ��� ���
//	if (cuurentDay == 0){ return; }
//
//	// ������ �������� ���ĵ� ������ �߿��� 
//	// ���س��� ���� ������ �����鸸 �ٸ� �켱 ť�� ��Ƶд�(���� ��������)
//	while (!PriorityQueue_DeadLine_Value.empty())
//	{
//		myPair = PriorityQueue_DeadLine_Value.top();
//		if (cuurentDay == myPair.first)
//		{
//			PriorityQueue_Value.push(myPair.second);
//			PriorityQueue_DeadLine_Value.pop();
//			continue;
//		}
//		break;
//	}
//
//	// ������ ��Ƶ� ť���� 1���� ������ ����� �����ش�.
//	if(!PriorityQueue_Value.empty())
//	{
//		result += PriorityQueue_Value.top();
//		PriorityQueue_Value.pop();
//	}
//
//	// ���س��� 0 �� �ɶ����� ��͸� ���
//	Recursive(cuurentDay - 1);
//}
//
//int main()
//{
//
//	Initailization();
//	// ��� ����
//	Recursive(taskDeadlineMax);
//	cout << result;
//	return 0;
//}