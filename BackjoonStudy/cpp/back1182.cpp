//#include <iostream>
//
//using namespace std;
//
//int N, S, result;
//
//// ���� ����� �� ���� ��ũ�η� ��� 
//#define MAX 20
//
//int numbers[MAX];
//
//void SettingCondition()
//{
//	result = 0;
//
//	cin >> N >> S;
//
//	for (int i = 0; i < N; i++)
//	{
//		cin >> numbers[i];
//	}
//}
//
//void DFS(int index, int total)
//{
//	if (index == N)
//	{
//		if (total == S)
//		{
//			result++;
//			return;
//		}
//		//�ε��� �������� ����
//		return;
//	}
//
//	// �ش� �ε����� ���Ҹ� ����Ҷ� / ���Ҷ�
//	DFS(index + 1, total + numbers[index]);
//	DFS(index + 1, total);
//}
//
//int main()
//{
//	// ����
//	SettingCondition();
//	DFS(0,0);
//	
//	// S = 0 �̸� ó�� ���� �� ������ ���Ұ� ������ 
//	// total�� 0 �̹Ƿ� ī��Ʈ�� �ϳ� �ö󰣴�.
//	if (S == 0) 
//	{
//		result--;
//	}
//	cout  << result;
//	return 0;
//}