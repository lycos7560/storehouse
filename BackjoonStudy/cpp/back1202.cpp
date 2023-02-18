#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// ������ ���� N, ������ ���� K
int N, K;

// ��� ���� ������ int�� �ִ� ������ �Ѿ �� ����
long long result = 0;

//<������ ��ġ, ������ ����, �������� ����>
multimap<int, int, greater<int>> jewelryMultimap;

// <������ ���� , ��� üũ>
// ��� üũ�� ����� �������� ��Ƽ�� ���Ķ����� ���
multiset<int> bagMultiset;
//��� ���԰� ���� ������� ���ĵ� ����

// �ݺ��� ����
multiset<int>::iterator it;


//  ó�� �ʱ�ȭ �Լ�
void Initializaion()
{
	cin >> N >> K;

	int tempW = 0;
	int tempV = 0;
	int temp = 0;

	// ������ ������ ���� ���Կ� ��ġ
	while (temp < N)
	{
		cin >> tempW >> tempV;
		jewelryMultimap.insert({ tempV, tempW });
		temp++;
	}
	temp = 0;

	// ���� ������ ���� ��� ���� ������ �Է�
	while (temp < K)
	{
		cin >> tempW;
		bagMultiset.insert(tempW);
		temp++;
	}
	// ������ ������������ ����
}

void AlgorithmOfGreed()
{
	// ��ġ�� ���� ������� ���ĵ� �������� �ѹ��� ��ȸ�Ѵ�.
	for (auto& elem : jewelryMultimap)
	{
	    // ��� ���԰� ���� ������ ���ĵ� �����
		// �����߿��� ������ ���� �̻��� ���� ���� ����� ���� ã��
		for (it = bagMultiset.lower_bound(elem.second);it != bagMultiset.end(); it++)
		{
			//�ش� ������ ã���� ������� ��ġ ���ϰ�
			result += elem.first;
			// �ش� ������ ����
			bagMultiset.erase(it);
			break;
		}
	}
}

int main()
{
	// �ʱ�ȭ
	Initializaion();
	// �׸��� �˰���
	AlgorithmOfGreed();
	cout << result;
	return 0;
}