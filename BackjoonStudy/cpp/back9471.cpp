#include <iostream>
#include <list>

using namespace std;

list<pair<int, int>> tcList;
list<pair<int, int>> resultList;

// 문제의 입력을 처리하는 함수
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

// 피사노의 주기를 확인하는 함수
int PeriodOfPisano(int tc)
{
	int a = 0, b = 1, cnt = 0, temp =0;

	// 주기가 나올때까지 반복해준다.
	while (true)
	{
		// 모듈러 산술 분배법칙
		temp = ((a % tc) + (b % tc)) % tc;
		a = b;
		b = temp;
		cnt++; // 주기가 얼마인지 체크

		// 나머지로 나눈 값이 처음과 같은 0과 1의 순서로 나온다면, 다시 주기가 반복된다는 뜻
		// (F2 = F1 + F0 , 나머지도 계속 반복을 하게 된다.)
		if (a == 0 && b == 1) break; 
	}

	return cnt; // 주기 리턴
}

int main()
{
	GetInput(); // 입력 받기
	
	// 테스트 케이스만큼 순회 
	for (auto iter = tcList.begin(); iter != tcList.end(); iter++) { // 결과값 출력
		cout << iter->first << " " << PeriodOfPisano(iter->second) << "\n"; 
	}

	return 0;
}