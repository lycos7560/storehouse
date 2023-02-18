#include <iostream>
#include <list>

using namespace std;

list<pair<int, string>> pairList;
list<pair<int, string>>::iterator it;
pair<int, string> myPair;

int main()
{
	int N = 0;

	string temp = "";

	cin >> N;

	while (N-- > 0) { 
		// myPair.first : 반복 횟수, myPair.second : 문자열
		cin >> myPair.first >> myPair.second; 
		pairList.push_back(myPair); // 리스에 추가
	}
	
	// 리스트를 순회
	for (it = pairList.begin(); it != pairList.end(); it++) {
		
		//문자열 초기화
		temp = "";

		// 문자열의 길이만큼 반복 (모든 문자열을 R만큼 반복함)
		for (int j = 0; j < it->second.length(); j++) { 

			// j 인덱스 문자를 R번 반복(it->first)
			for (int i = 0; i < it->first; i++) {

				// temp 문자열에 추가
				temp.push_back(it->second[j]);
			}
		}
		cout << temp << "\n";
	}

	return 0;

}