#include <iostream>
#include <list>

using namespace std;

string answer[2] = { "yes", "no" };

list<string> answerList;

int temp;

int main()
{
	string str = "";
	
	while (true) { // 계속 반복
		
		cin >> str;
		
		if (str == "0") break; // 0을 입력받으면 stop
		temp = 0;
		
		for (int i = 0; i < str.length()/2; i++) { // 홀수일 경우 가운데는 의미가 없음
			
			if (str[i] != str[str.length() -1 - i]) { temp = 1; }

		}

		answerList.push_back(answer[temp]); // 리스트에 답을 넣는다
	}

	// 리스트를 순회하면서 출력
	for (auto it = answerList.begin(); it != answerList.end(); it++) {
		cout << *it << "\n";
	}

	return 0;
}