#include <iostream>
#include <list>

using namespace std;

list<pair<int, int>> tcList;
list<pair<int, int>> resultList;

// ������ �Է��� ó���ϴ� �Լ�
void GetInput()
{
	int N;
	cin >> N;
	pair<int, int> tempPair;
	while (N-- > 0) {
		cin >> tempPair.first >> tempPair.second;
		tcList.push_back(tempPair);
	}
}

// �ǻ���� �ֱ⸦ Ȯ���ϴ� �Լ�
int PeriodOfPisano(int tc)
{
	int a = 0, b = 1, cnt = 0, temp =0;

	// �ֱⰡ ���ö����� �ݺ����ش�.
	while (true)
	{
		// ��ⷯ ��� �й��Ģ
		temp = ((a % tc) + (b % tc)) % tc;
		a = b;
		b = temp;
		cnt++; // �ֱⰡ ������ üũ

		// �������� ���� ���� ó���� ���� 0�� 1�� ������ ���´ٸ�, �ٽ� �ֱⰡ �ݺ��ȴٴ� ��
		// (F2 = F1 + F0 , �������� ��� �ݺ��� �ϰ� �ȴ�.)
		if (a == 0 && b == 1) break; 
	}

	return cnt; // �ֱ� ����
}

int main()
{
	GetInput(); // �Է� �ޱ�
	
	// �׽�Ʈ ���̽���ŭ ��ȸ 
	for (auto iter = tcList.begin(); iter != tcList.end(); iter++) { // ����� ���
		cout << iter->first << " " << PeriodOfPisano(iter->second) << "\n"; 
	}

	return 0;
}