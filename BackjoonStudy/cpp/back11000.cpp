//#include <iostream>
//#include <set>
//#include <queue>
//
//using namespace std;
//
////�켱 ���� Q�� ����Ͽ� �Է°��� �������ش�.
//priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myQueue;
//
//int result = 1;
//
//// ���ǵ��� ������ ����
//pair<int, int> mypair;
//
//// ��Ƽ���� ����ϱ� ���� �غ�
//multiset<int> mymultiset;
//multiset<int>::iterator iter;
//
//// �Է°� �ʱ�ȭ �Լ�
//void Initialization()
//{
//	int N = 0;
//	int S = 0;
//	int T = 0;
//	cin >> N;
//	while (N > 0)
//	{
//		cin >> S >> T;
//		myQueue.push(make_pair(S, T));
//		N--;
//	}
//}
//
//int main()
//{
//	// �Է°��� �޾��ݴϴ�.
//	Initialization();
//	mypair = myQueue.top();
//	myQueue.pop();
//	mymultiset.insert(mypair.second);
//
//	while (!myQueue.empty())
//	{
//		mypair = myQueue.top();
//		myQueue.pop();
//	 
//		if (mypair.first < *mymultiset.begin())
//		{
//			mymultiset.insert(mypair.second);
//			result++;
//			continue;
//		}
//
//		iter = mymultiset.lower_bound(mypair.first);
//
//		// ���� ���� ���� ���� set���� �����ϰ� �� �߰����ش�.
//		if (*iter == mypair.first)
//		{
//			mymultiset.erase(iter);
//		}
//		else
//		{
//			mymultiset.erase(--iter);
//		}
//		
//		mymultiset.insert(mypair.second);
//	}
//	cout << result;
//	return 0;
//}