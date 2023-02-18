#include <iostream>
#include <map>
#include <cmath>

using namespace std;

//cubeMultimap 은 내림차순으로 정렬된다. 
multimap<int, int, greater<int>> cubeMultimap;
//cubeMultimap 순회를 위한 반복자
multimap<int, int, greater<int>>::iterator iter;


int length, width, height;
int numberOfCubes, cnt = 0;
int tempOne, tempTwo;
bool failCheck = false;

// 조건을 초기화 해주는 함수
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

// 분할 정복을 위한 함수 (X, Y, Z, 반복자)
void divisionConquest(int length, int width, int height, multimap<int, int, greater<int>>::iterator iter)
{
	// 만약 X, Y, Z 중에서 0이 되는 값이 있다면 리턴
	if (length == 0 || width == 0 || height == 0) return;

   // 분할정복 로직부분
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

	// 만약 큐브의 조건이 만족하지 않는다면 실패 마킹
	failCheck = true;
	return;
}


int main()
{

	Initializaion();

	// cubeMultimap의 가장 높은 값부터 시작
	iter = cubeMultimap.begin();
	divisionConquest(length, width, height, iter);

	// 실패 마킹이 true 면 항상 -1 출력
	if (failCheck) cout << -1;
	else cout << cnt; // 아니면 큐브의 개수를 출력한다.

	return 0;
}