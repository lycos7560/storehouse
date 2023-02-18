#include <iostream>
#include <map>
#include <cmath>

using namespace std;

//cubeMultimap �� ������������ ���ĵȴ�. 
multimap<int, int, greater<int>> cubeMultimap;
//cubeMultimap ��ȸ�� ���� �ݺ���
multimap<int, int, greater<int>>::iterator iter;


int length, width, height;
int numberOfCubes, cnt = 0;
int tempOne, tempTwo;
bool failCheck = false;

// ������ �ʱ�ȭ ���ִ� �Լ�
void Initializaion()
{
	cin >> length >> width >> height >> numberOfCubes;
	while (numberOfCubes > 0)
	{
		cin >> tempOne >> tempTwo;
		cubeMultimap.insert(make_pair(pow(2, tempOne), tempTwo));
		numberOfCubes--;
	}
}

// ���� ������ ���� �Լ� (X, Y, Z, �ݺ���)
void divisionConquest(int length, int width, int height, multimap<int, int, greater<int>>::iterator iter)
{
	// ���� X, Y, Z �߿��� 0�� �Ǵ� ���� �ִٸ� ����
	if (length == 0 || width == 0 || height == 0) return;

   // �������� �����κ�
	for (;iter != cubeMultimap.end(); iter++)
	{
		if (iter->second != 0 && length >= iter->first && width >= iter->first && height >= iter->first)
		{
			iter->second--;
			cnt++;
			divisionConquest(iter->first, iter->first, width - (iter->first), iter);
			divisionConquest(length - iter->first, height, width, iter);
			divisionConquest(height - iter->first, width, iter->first, iter);
			return;
		}
	}

	// ���� ť���� ������ �������� �ʴ´ٸ� ���� ��ŷ
	failCheck = true;
	return;
}


int main()
{

	Initializaion();

	// cubeMultimap�� ���� ���� ������ ����
	iter = cubeMultimap.begin();
	divisionConquest(length, width, height, iter);

	// ���� ��ŷ�� true �� �׻� -1 ���
	if (failCheck) cout << -1;
	else cout << cnt; // �ƴϸ� ť���� ������ ����Ѵ�.

	return 0;
}