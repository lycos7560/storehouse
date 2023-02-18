#include <iostream>
#include <list>
using namespace std;

list<string> stringList;
list<string>::iterator it;

string temp;
int N, result;

int main()
{	
	// 테스트 케이스의 수를 N에 넣습니다.
	cin >> N;
	// 테스트 케이스만큼 문자열을 입력받고
	// 리스트에 넣습니다.
	while (N-- >0) {
		cin >> temp;
		stringList.push_back(temp);
	}

	// 입력받은 문자열 리스트를 순회 
	for (it = stringList.begin(); it != stringList.end(); it++) {

		temp = *it;

		N = 0; // O 연속 카운트
		result = 0; // 점수의 총합

		// 만약 temp[i] == 'O' 이라면 N의 카운트를 하나 늘려주고 (연속된 O의 개수 구현 )
		// 아니라면 N을 O으로 만들어준다.
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == 'O') { N++; } 
			else { N = 0; }
			result += N;
		}

		// 해당 문자열의 반복이 끝나면 결과값 출력

		cout << result << "\n";

	}

	return 0;
}